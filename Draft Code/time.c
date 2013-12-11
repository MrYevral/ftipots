#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "time.h"


/* Returns an int which is the number of mins difference between two times
 * takes two time structs
 */

int time_past(time *a,time *b){
	int a_sec;
	int b_sec;
	a_sec = to_sec(a);
	b_sec = to_sec(b);



}
int to_sec(time *in){
	int out;
	out = 0;
	out += in->sec;

}
