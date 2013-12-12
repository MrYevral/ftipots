#include "navigation.h"
#include "time.h"
#include "definitions.h"

struct s{
	time time_last_seen;
	char ais[AIS_LENGTH];
	location last_known_location;
	double direction;
	double speed;
	struct s *next;
};
typedef struct s ship;

ship *get_ship(FILE *fp,time *t);
ship *get_ships(char *fn);
location get_current_location(ship *s, time t);
