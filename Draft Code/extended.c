/* 
* File: main.c
* Author: hac22(AKA MrYevral)
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rescue_asset.h"
#include "mayday.h"
#include "ship.h"
#include "definitions.h"


char fn_asset[FN_LENGTH];
char fn_mayday[FN_LENGTH];
char fn_ships[FN_LENGTH];
FILE *log_fp;
rescue_asset *asset_root;
ship *ship_root;
mayday *mayday_root;

// for forward reference
void solve(mayday *root,rescue_asset *assets,ship *ships);



int main(int argc, char** argv) {

	//ask user for files
	printf("Welcome to FTIPOTS a mayday response software developed by hac22(aka MrYevral)\n");
	printf("Please enter the filename of your rescue assets: ");
	scanf("%s",fn_asset);
	printf("\nPlease enter the filename of your ships file: ");
	scanf("%s",fn_ships);
	printf("\nPlease enter the filename of your mayday file: ");
	scanf("%s",fn_mayday);
	printf("\n\n\n");
	//read in files
	asset_root = get_assets(fn_asset);
	printf("Assets loaded.\n");
	ship_root = get_ships(fn_ships);
	printf("Ships loaded.\n");
	mayday_root = get_maydays(fn_mayday);
	printf("Mayday(s) found...\n\n");
	solve( mayday_root, asset_root, ship_root );
	return (EXIT_SUCCESS);
}

void solve(mayday *root, rescue_asset *assets, ship *ships) {
printf("Logging Started\n");
log_fp = fopen(FILE_LOG);
fprintf(log_fp,"NEW_LOG\n----------\n");
fclose(log_fp);
mayday *mayday_current = root;
ship *ship_current = ships;
int found_ais = 0;

while(mayday_current!= NULL) {
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
			if(current_location.lat>MIN_LAT&&current_location.lng<MAX_LAT&&current_location.lng>MIN_LNG&&current_location.lng<MAX_LNG){
				printf("    servicing...\n");
				log_fp=fopen(FILE_LOG);
				fprintf(log_fp,"    servicing...\n");
				fclose(log_fp);
				rescue_asset *hele_responding;
				rescue_asset *life_boat_responding;
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
