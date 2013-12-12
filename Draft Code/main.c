#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rescue_asset.h"
#include "mayday.h"
#include "ship.h"
#include "definitions.h"


char fn_asset[101];
char fn_mayday[101];
char fn_ships[101];
FILE *log_fp;
rescue_asset *asset_root;
ship *ship_root;
mayday *mayday_root;

// for forward reference
void solve(mayday *root,rescue_asset *assets,ship *ships);



int main(int argc, char** argv) {
//	char *fn = "rescue_assets.txt";
//	rescue_asset *root;
//	root = get_assets(fn);
//	print_assets(root);
/*	char *fn = "mayday_1.txt";
	mayday *root;
	root = get_maydays(fn);
	char *fn = "ships_1.txt";
	ship *root;
	root = get_ships(fn);
	printf("success");*/

	printf("Welcome to FTIPOTS a mayday response software developed by hac22(aka MrYevral)\n");
	printf("Please enter the filename of your rescue assets: ");
	printf("\n\n\n");
	scanf("%s",fn_asset);
	scanf("%s",fn_ships);
	scanf("%s",fn_mayday);
	asset_root = get_assets(fn_asset);
	printf("Assets loaded.\n");



	log_fp = fopen("haap.txt","a");
	fprintf(log_fp,"yacunt\n");
	fclose(log_fp);
	
	
	
	ship_root = get_ships(fn_ships);
	printf("Ships loaded.\n");
	mayday_root = get_maydays(fn_mayday);
	printf("Mayday(s) found...\n\n");
	solve( mayday_root, asset_root, ship_root );
	return (EXIT_SUCCESS);
}

void solve(mayday *root, rescue_asset *assets, ship *ships) {
printf("Logging Started\n");
log_fp = fopen("log.txt","a");
fprintf(log_fp,"NEW_LOG\n----------");
fclose(log_fp);
mayday *mayday_current = root;
ship *ship_current = ships;
int found_ais = 0;

while(mayday_current!= NULL) {
	/*SAVING LOGIC
	 * search through ships till an AIS match
	 * when ais match calc ships current position
	 * take current location, find nearest helecopter and lifeboat capable of servicing mayday sender
	 * REPEAT
	*/

	found_ais = 0;
	ship_current = ships;
	printf("Mayday received!\n");

	log_fp = fopen(FILE_LOG);
	fprintf(log_fp,"Mayday received!\n");
	fclose(log_fp);
	while(ship_current!=NULL){
		if(strcmp(mayday_current->ais, ship_current->ais) == 0) {
			printf("  Known AIS:%s\n", ship_current->ais);
			log_fp = fopen(FILE_LOG);
			fprintf(log_fp,"  Known AIS:%s\n", ship_current->ais);
			fclose(log_fp);
			found_ais = 1;
			
			location current_location;
			current_location = get_current_location(ship_current, mayday_current->time_of_incident);
			if(current_location.lat>51.667&&current_location.lng<52.833&&current_location.lng>-6.67&&current_location.lng<-3.883){
				printf("    servicing...\n");
				log_fp=fopen(FILE_LOG);
				fprintf(log_fp,"    servicing...\n");
				fclose(log_fp);
				rescue_asset *hele_responding;
				rescue_asset *life_boat_responding;
				//hele_responding = malloc(sizeof(rescue_asset));
				//life_boat_responding = malloc(sizeof(rescue_asset));
				hele_responding = responding('h', current_location, mayday_current->helecopter_help, assets);
				life_boat_responding = responding('l', current_location, mayday_current->lifeboat_help, assets);
			}
			else{
			//NOT MY PROBLEM
				printf("    Out of area: NOT servicing.\n");
				log_fp=fopen(FILE_LOG);
				fprintf(log_fp,"    Ouf of area: NOT servicing.\n");
				fclose(log_fp);
			}
		
		}
		ship_current = ship_current->next;
	}
	if( found_ais ){
		printf("Mayday processed.\n----------------\n\n");
		log_fp=fopen(FILE_LOG);
		fprintf(log_fp,"Mayday processed.\n----------------\n\n");
		fclose(log_fp);
	}
	else{
		printf("  ** UNKNOWN AIS: cannot process.\n----------------\n\n");
		log_fp=fopen(FILE_LOG);
		fprintf(log_fp,"  ** UNKNOWN AIS: cannot process.\n----------------\n\n");
		fclose(log_fp);
	}
	mayday_current = mayday_current->next;

}

}
