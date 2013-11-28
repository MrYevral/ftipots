#include<stdio.h>
#include<stdlib.h>

struct Rescue_assest {
	char callsign[56];
	char asset_type;
	float longitude;
	float latitude;
	int max_speed;
    	int restock_time;
	struct Rescue_asset *next;
} ;




int main(int argc, char** argv) {
	printf("Hello, World!\n");
        
        
        
        
	return (EXIT_SUCCESS);
}


