#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mayday.h"
mayday *temp;
int check;
short b_day;
short b_month;
int b_year;
short b_min;
short b_sec;
short b_hour;
char b_ais[5];
int b_lifeboat_help;
int b_helecopter_help;

mayday *get_maydays(char *fn){
	FILE *fp = fopen(fn,"r");
	mayday *root;
	mayday *current;
	mayday *last;
	current = get_mayday(fp);
	root = current;
	last = current;
	while((current = get_mayday(fp)) != NULL){
		last->next = current;
		last = current;
	}
	fclose(fp);
	return root;
}
mayday *get_mayday(FILE *fp_maydays){
	check = fscanf(fp_maydays,"%hd %hd %d %hd %hd %hd %c %d %d",&b_day,
		&b_month, &b_year, &b_hour, &b_min, &b_sec, b_ais,&b_lifeboat_help, &b_helecopter_help);
	if(check == EOF)
		return NULL;
	temp = malloc(sizeof(mayday));
	temp->day = b_day;
	temp->month = b_month;
	temp->year = b_year;
	temp->min = b_min;
	temp->hour = b_hour;
	strcpy(temp->ais,b_ais);
	temp->lifeboat_help = b_lifeboat_help;
	temp->helecopter_help = b_lifeboat_help;
	temp->next = NULL;
	return temp;




}
