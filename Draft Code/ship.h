#include "naviagion.h"
struct s{
	char aid[6];
	location last_known_location;
	double direction;
	double speed;
};
struct d{
	short day;
	short month;
	int year;
	short hour;
	short min;
	short sec;
};
typedef struct s ship;
typedef struct d date_time;
ship *get_ship(FILE *fp);
ship *get_ships(char *fn);

