#include <stdio.h>
#include <stdlib.h>
#include "rescue_asset.h"
#include "mayday.h"
#include "ship.h"


char fn_asset[101] = "rescue_assets.txt";
char *fn_mayday="mayday_1.txt";
char *fn_ships="ships_1.txt";
rescue_asset *asset_root;
ship *ship_root;
mayday *mayday_root;


void solve(mayday *root,rescue_asset *assets,ship *ships);
location get_current_location(ship *a, time b);



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

printf("Welcome to FTIPOTS a mayday response software developed by hac22(aka MrYevral)\nPlease enter the filename of your rescue assets: ");
//scanf("%s",fn_asset);
asset_root = get_assets(fn_asset);
printf("assets done\n");
ship_root = get_ships(fn_ships);
printf("ships done\n");
mayday_root = get_maydays(fn_mayday);
printf("maydays done\n");
solve( mayday_root, asset_root, ship_root );
	return (EXIT_SUCCESS);
}

void solve(mayday *root, rescue_asset *assets, ship *ships){
mayday *mayday_current = root;
rescue_asset *asset_current = assets;
ship *ship_current = ships;
printf("plig\n");
while(mayday_current!= NULL){
	/*SAVING LOGIC
	 * search through ships till an AIS match
	 * when ais match calc ships current position
	 * take current location, find nearest helecopter and lifeboat capable of servicing mayday sender
	 * AGAIN
	 */
	printf("glug\n");
	while(ship_current!=NULL){
		if(strcmp(mayday_current->ais, ship_current->ais) == 0){
			printf("hello\n");
			
			location current_location;
			current_location = get_current_location(ship_current, mayday_current->time_of_incident);
			if(current_location.lat>51.667&&current_location.lng<52.833&&current_location.lng>-6.67&&current_location.lng<-3.883){
				printf("servicing\n");
				rescue_asset *hele_responding;
				rescue_asset *life_boat_responding;
				//hele_responding = malloc(sizeof(rescue_asset));
				//life_boat_responding = malloc(sizeof(rescue_asset));
				printf("XXX - :%s:\n", assets->callsign );
				hele_responding = responding('h', current_location, mayday_current->helecopter_help, assets);
				life_boat_responding = responding('l', current_location, mayday_current->lifeboat_help, assets);
			}
			else{
			//NOT MY PROBLEM
				printf("not servicing\n");
			}
		
		}
		ship_current = ship_current->next;
	}
	

	mayday_current = mayday_current->next;
}


}
