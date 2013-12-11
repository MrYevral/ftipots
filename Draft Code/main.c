#include <stdio.h>
#include <stdlib.h>
#include "rescue_asset.h"
#include "mayday.h"

int main(int argc, char** argv) {
//	char *fn = "rescue_assets.txt";
//	rescue_asset *root;
//	root = get_assets(fn);
//	print_assets(root);
/*	char *fn = "mayday_1.txt";
	mayday *root;
	root = get_maydays(fn);*/
	char *fn = "ships_1.txt";
	ship *root;
	root = get_ships(fn);
	printf("success");
	return (EXIT_SUCCESS);
}


