/**
 * File: rescue_asset.h(DRAFT)
 * Author: hac22 (MrYevral)
 * Created on: 2/12/2013
 */
#include"navigation.h"
#include"time.h"
#include "definitions.h"
struct r_a{
	char callsign[STR_LENGTH];
	char asset_type;
	char base_name[STR_LENGTH];
	location base_location;
	double speed;
	int max_deploy_time;
	int turn_around_time;
	struct r_a *next;
	time when_free;
};

typedef struct r_a rescue_asset;

rescue_asset *get_assets(char *fn);
rescue_asset *get_asset(FILE *fp);
void print_assets(rescue_asset *root);

rescue_asset *responding( char, location, int, rescue_asset *);
