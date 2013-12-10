typedef struct{
	short secs;
	short mins;
	short hours;
	char assets_used[];
	event *next;
} event;
