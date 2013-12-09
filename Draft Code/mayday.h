typedef struct {
	short day;
	short month;
	int year;
	short hour;
	short min;
	short sec;
	char ais[10];
	int lifeboat_help;
	int helecopter_help;
} mayday;

mayday *fget_mayday(FILE *file);
