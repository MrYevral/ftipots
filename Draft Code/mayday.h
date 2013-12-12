#include "time.h"
#include "definition.h"
struct md{
	time time_of_incident;
	char ais[AIS_LENGTH];
	int lifeboat_help;
	int helecopter_help;
	struct md *next;
}; 

typedef struct md mayday;

mayday *get_maydays(char *fn);
mayday *get_mayday(FILE *fp);
