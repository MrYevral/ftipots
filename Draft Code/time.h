#ifndef TIMESTRUCT
#define TIMESTRUCT

struct t{
	int day;
	int month;
	int year;
	int hour;
	int min;
	int sec;
};
typedef struct t time;

int time_past( time a, time b );
int to_sec( time a);

#endif
