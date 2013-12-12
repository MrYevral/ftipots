#include "time.h"
struct md{
	time time_of_incident;
	char ais[6];
	int lifeboat_help;
	int helecopter_help;
	struct md *next;
}; 

typedef struct md mayday;

mayday *get_maydays(char *fn);
mayday *get_mayday(FILE *fp);
