#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rescue_asset.h"

rescue_asset *temp;
char b_callsign[30];
char b_asset_type;
char b_base_name[30];
double b_latt;
double b_long;
double b_speed;
int b_max_deploy;
int b_turn_around_time;
int check;
rescue_asset *get_asset(FILE *fp_assets){
	check = fscanf(fp_assets,"%s %c %s %lf %lf %lf %d %d", b_callsign, 
			&b_asset_type, b_base_name, &b_latt, &b_long, &b_speed, 
			&b_max_deploy, &b_turn_around_time);	
	if(check == EOF)
		return NULL;
	temp = malloc(sizeof(rescue_asset));
	strcpy(temp->callsign,b_callsign);
	temp->asset_type = b_asset_type;
	strcpy(temp->base_name,b_base_name);
	temp->base_location.lat = b_latt;
	temp->base_location.lng = b_long;
	temp->speed = b_speed;
	temp->max_deploy_time = b_max_deploy;
	temp->turn_around_time = b_turn_around_time;
	temp->next = NULL;
	return temp;
	
}
rescue_asset *get_assets(char *fn){
	FILE *fp = fopen(fn,"r");
	rescue_asset *root;
	rescue_asset *current;
	rescue_asset *last;
	current = get_asset(fp);
	root = current;
	last = current;
	while((current = get_asset(fp)) != NULL){
		last->next = current;
		last = current;
	}
	fclose(fp);
	return root;
}
void print_asset(rescue_asset *ra){
	printf("%s\n",ra->callsign);
}
void print_assets(rescue_asset *root){
	rescue_asset *current = root;

		
	while (current != NULL){

		print_asset(current);
		current = current->next;
	}
}
rescue_asset *responding(char type,location *destination,int time_needed,rescue_asset *root){
	rescue_asset *current;
	rescue_asset *out;
	current = root;
	out = NULL;
	double min_deploy = 900000;
	double temp;
	double asset_deploy = 900000;
	if(type == "h"){
		while(current !=NULL){
			if(current->asset_type =="h"||current->asset_type =="H"){
				temp = great_circle(current->base_location,*destination);
				min_deploy = (temp/current->speed)*2+time_needed;
				if(min_deploy<current->max_deploy_time && min_deploy<asset_deploy ){
					out = current;
					asset_deploy = min_deploy;
				}
			}
			current = current->next;
		}
		return current;
	}
	else{
		while(current !=NULL){
			if(current->asset_type =="l"||current->asset_type =="L"){
				temp = great_circle(current->base_location,*destination);
				min_deploy = (temp/current->speed)*2;
				if(min_deploy<current->max_deploy_time && min_deploy<asset_deploy ){
					out = current;
					asset_deploy = min_deploy;
				}
			}
			current = current->next;
		}
		printf("haha");
		return current;


}
}
