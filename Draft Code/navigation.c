#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"navigation.h"

double great_circle(location a,location b){
double lat_diff;
double lng_diff;
double out;
lat_diff = a.lat-b.lat;
lng_diff = a.lng-b.lng;
lat_diff*=60;
lng_diff*=60;
out =sqrt(pow(lat_diff,2)+pow(lng_diff,2));
return out;
}
