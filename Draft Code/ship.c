#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ship.h"


ship *temp;

time *last_known_time;
char* b_ais;
location b_last_known_location;

date_time *get_dt(FILE *fp){
	check=(fscamf(fp,"",);
	last_known_time = malloc(sizeof(last_known_time));
	last_known_time->day = b_day;
	last_known_time->month= b_month;
 	last_known_time->year = b_year;
	last_known_time->hour = b_hour;
	last_known_time->min = b_min;
	last_known_time->sec = b_sec;
}
ship *get_ship(FILE *fp){
	check = fscanf(fp,"",);
	if(check == EOF)
		return NULL;
	//allocate details
	temp = malloc(sizeof(ship));
}
ship *get_ships(char *fn){
	FILE *fp = fopen(fn,"r");
	ship *root;
	ship *current;
	ship *last;
	time = get_dt(fp);
	current = get_ship(fp);
	root = current;
	last = current;
	while((current = get_ship(fp))!=NULL){
		last->next=current;
		last = current;
	}
	fclose(fp)
	return root;
}
