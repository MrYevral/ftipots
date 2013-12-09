#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char callsign[56];
	char asset_type;
	float longitude;
	float latitude;
	int max_speed;
    	int restock_time;
	struct Rescue_asset *next;
} rescue_asset ;


int main(int argc, char** argv) {

	return (EXIT_SUCCESS);
}


