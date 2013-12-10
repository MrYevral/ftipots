#include "naviagion.h"
#include "time.h"
struct s{
	time time_last_seen;
	char aid[6];
	location last_known_location;
	double direction;
	double speed;
};
typedef struct s ship;
ship *get_ship(FILE *fp);
ship *get_ships(char *fn);

