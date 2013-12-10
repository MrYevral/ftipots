#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ship.h"


ship *temp;
date_time *last_known_time;
char* b_ais;
location b_last_known_location;

date_time *get_dt(FILE *fp){

//TODO get date stuff sorted

}
ship *get_ship(FILE *fp){
	check = fscanf(fp,"",)
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
	date_time
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
