#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rescue_asset.h"
rescue_asset *temp;
char b_callsign[STR_LENGTH];
char b_asset_type;
char b_base_name[STR_LENGTH];
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
	strcpy(temp->callsign, b_callsign);
	temp->asset_type = b_asset_type;
	strcpy(temp->base_name, b_base_name);
	temp->base_location.lat = b_latt;
	temp->base_location.lng = b_long;
	temp->speed = b_speed;
	temp->max_deploy_time = b_max_deploy;
	temp->turn_around_time = b_turn_around_time;
	temp->when_free.hour = 0;
	temp->when_free.min = 0;
	temp->when_free.sec  = 0;
	temp->when_free.day = 0;
	temp->when_free.month = 0;
	temp->when_free.year  = 0;
	temp->next = NULL;
	return temp;
	
}

rescue_asset *get_assets(char *fn){
	FILE *fp = fopen(fn, "r");
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

rescue_asset *responding(char type, location destination, int time_needed, rescue_asset *drummond){

	rescue_asset *current;
	rescue_asset *out;

	current = drummond;
	out = NULL;
	double min_deploy = 900000;
	double temp_dist;
	double asset_deploy = 900000;

	if(type == 'h'){
		while(current != NULL){
			if(current->asset_type =='h'||current->asset_type =='H'){
				temp_dist = great_circle(current->base_location, destination);
				min_deploy = (temp_dist/current->speed)*2+time_needed;
				if(min_deploy<current->max_deploy_time && min_deploy<asset_deploy ){
					out = current;
					out->when_free
					asset_deploy = min_deploy;
				}
			}
			current = current->next;
		}
	}
	else{
		while(current != NULL){
			if(current->asset_type =='l'||current->asset_type =='L'){
				temp_dist = great_circle(current->base_location, destination);
				min_deploy = (temp_dist/current->speed)*2;
				if(min_deploy<current->max_deploy_time && min_deploy<asset_deploy ){
					out = current;
					asset_deploy = min_deploy;
				}
			}
			current = current->next;
		}


	}
	printf("      asset sent = %s\n",out->callsign);
	FILE *log_fp = fopen(FILE_LOG);
	fprintf(log_fp,"      asset sent = %s\n",out->callsign);
	fclose(log_fp);
	return out;
}
