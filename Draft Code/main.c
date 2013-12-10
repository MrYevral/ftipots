#include <stdio.h>
#include <stdlib.h>
#include "rescue_asset.h"

int main(int argc, char** argv) {
	char *fn = "rescue_assets.txt";
	rescue_asset *root;
	root = get_assets(fn);
	print_assets(root);
	return (EXIT_SUCCESS);
}


