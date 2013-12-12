#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "ship.h"



ship *temp;
time *last_known_time;
short b_day;
short b_month;
int b_year;
short b_hour;
short b_min;
short b_sec;
char b_ais[AIS_LENGTH];
double b_lat;
double b_lng;
double b_direction;
double b_speed;
int check;

time *get_dt(FILE *fp) {
	fscanf(fp,"%hd %hd %d %hd %hd %hd",&b_day, &b_month,
		&b_year, &b_hour, &b_min, &b_sec);
	last_known_time = malloc(sizeof(time));
	last_known_time->day = b_day;
	last_known_time->month= b_month;
 	last_known_time->year = b_year;
	last_known_time->hour = b_hour;
	last_known_time->min = b_min;
	last_known_time->sec = b_sec;
	return last_known_time;
}

ship *get_ship(FILE *fp, time *t) {
	check = fscanf(fp,"%s %lf %lf %lf %lf", b_ais , &b_lat, &b_lng,
		&b_direction, &b_speed);
	if(check == EOF)
		return NULL;
	temp = malloc(sizeof(ship));
	temp->time_last_seen = *t;
	strcpy(temp->ais, b_ais);
	temp->last_known_location.lat = b_lat;
	temp->last_known_location.lng = b_lng;
	temp->direction = b_direction;
	temp->speed = b_speed;
	temp->next = NULL;
	return temp;
}

ship *get_ships(char *fn) {
	FILE *fp = fopen(fn, "r");
	ship *root;
	ship *current;
	ship *last;
	last_known_time = get_dt(fp);
	current = get_ship(fp, last_known_time);
	root = current;
	last = current;
	while((current = get_ship(fp, last_known_time))!=NULL) {
		last->next=current;
		last = current;
	}
	fclose(fp);
	return root;
}

ship *find(char ais_to_find[10],ship *root) {
	bool found = false;
	ship *current;
	current = root;

	while(!found){
	if(current->ais!= ais_to_find) {
		if(current->next == NULL) {
			return NULL;
		}
		current = current->next;
	}
	else{
		found = true;
	}

	}
	return current;
}

location get_current_location(ship *in_peril, time current_time) {
	int tp = time_past(in_peril->time_last_seen, current_time);
	location out;
	out.lat = in_peril->last_known_location.lat + (in_peril->speed * cos((in_peril->direction * M_PI / 180)) * tp)/3600.0;
	out.lng = in_peril->last_known_location.lng + (in_peril->speed * sin((in_peril->direction * M_PI / 180)) * tp/cos((in_peril->last_known_location.lat*M_PI/180)))/3600.0;

	return out;
}

