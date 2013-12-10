struct e{
	time time_of_event;
	char assets_used[];
	struct e *next;
} event;
typedef struct e event;