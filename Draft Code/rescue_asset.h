/**
 * File: rescue_asset.h(DRAFT)
 * Author: hac22 (MrYevral)
 * Created on: 2/12/2013
 */
#include"navigation.h"
struct r_a{
	char callsign[30];
	char asset_type;
	char base_name[30];
	location base_location;
	double speed;
	int max_deploy_time;
	int turn_around_time;
	struct r_a *next;
};

typedef struct r_a rescue_asset;

rescue_asset *get_assets(char *fn);
rescue_asset *get_asset(FILE *fp);
void print_assets(rescue_asset *root);
