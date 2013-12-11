#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ship.h"


ship *temp;
time *last_known_time;
short b_day;
short b_month;
int b_year;
short b_hour;
short b_min;
short b_sec;
char* b_ais;
double b_lat;
double b_lng;
double b_direction;
double b_speed;

time *get_dt(FILE *fp){
	fscamf(fp,"%hd %hd %d %hd %hd %hd",&b_day, &b_month,
		&b_year, &b_hour, &b_min, &b_sec;
	last_known_time = malloc(sizeof(last_known_time));
	last_known_time->day = b_day;
	last_known_time->month= b_month;
 	last_known_time->year = b_year;
	last_known_time->hour = b_hour;
	last_known_time->min = b_min;
	last_known_time->sec = b_sec;
	return last_known_time;
}
ship *get_ship(FILE *fp, time t){
	check = fscanf(fp,"%s %lf %lf %lf %lf",b_ais , &b_lat, &b_lng,
		b_direction, b_speed);
	if(check == EOF)
		return NULL;
	temp = malloc(sizeof(ship));
	temp->time = t;
	strcpy(temp->ais,b_ais);
	temp->last_known_location.lat = b_lat;
	temp->last_known_location.lng = b_lng;
	temp->direction = b_direction;
	temp->speed = b_speed;
	temp->next = NULL;
	return temp;
	
}
ship *get_ships(char *fn){
	FILE *fp = fopen(fn,"r");
	ship *root;
	ship *current;
	ship *last;
	time = get_dt(fp);
	current = get_ship(fp,time);
	root = current;
	last = current;
	while((current = get_ship(fp))!=NULL){
		last->next=current;
		last = current;
	}
	fclose(fp)
	return root;
}
