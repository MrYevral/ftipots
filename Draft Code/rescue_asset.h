/**
 * File: rescue_asset.h(DRAFT)
 * Author: hac22 (MrYevral)
 * Created on: 2/12/2013
 */
#include"navigation.h"
typedef struct {
	char callsign[30];
	char asset_type;
	char base[30];
	location base;
	double speed;
	int max_deploy;
	int turn_around_time;
	rescue_asset *next;
} rescue_asset;

//rescue_asset *fget_assets(FILE *file);

void print(resuce_asset asset);
