#include <stdio.h>
#include <stdlib.h>
#include "rescue_asset.h"
#include "mayday.h"
#include "ship.h"


char fn_asset[101];
char *fn_mayday="mayday_1.txt";
char *fn_ships="ships_1.txt";
rescue_asset *asset_root;
ship *ship_root;
mayday *mayday_root;





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
scanf("%s",fn_asset);
asset_root = get_assets(fn_asset);
ship_root = get_ships(fn_ships);
mayday_root = get_maydays(fn_mayday);
	return (EXIT_SUCCESS);
}

void solve(mayday *root,rescue_asset *assets,ship *ships){
mayday *mayday_current;
rescue_asset *asset_current;
ship *ship_current;
while(mayday_current!= NULL){
	/*SAVING LOGIC
	 * search through ships till an AIS match
	 * when ais match calc ships current position
	 * take current location, find nearest helecopter and lifeboat capable of servicing mayday sender
	 * AGAIN
	 */
	while(ship_current!=NULL){
		if(mayday_current->ais == ship_current->ais){
			
			location *current_location;
			current_location = get_current_location(ship_current,mayday_current->time_of_incident);
			if(current_location->lat>51.667&&current_location->lng<52.833&&current_location->lng>-6.67&&current_location->lng<-3.883){
				rescue_asset *hele_responding;
				rescue_asset *life_boat_responding;
				hele_responding = malloc(sizeof(rescue_asset));
				life_boat_responding = malloc(sizeof(rescue_asset));
				hele_responding = responding("h",current_location,mayday_current->helecopter_help);
				life_boat_responding = responding("l",current_location,mayday_current->lifeboat_help);
			}
			else{
			//NOT MY PROBLEM
			}
		
		}
		ship_current = ship_current->next;
	}
	


}


}
