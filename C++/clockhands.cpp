#include <bits/stdc++.h>
using namespace std;
int calcAngle(double h, double m)
{
    if (h == 12) h = 0;

    float hour_angle = 0.5 * (h * 60 + m);
    float minute_angle = 6 * m;
 
    float angle = abs(hour_angle - minute_angle);
    if(angle>180){
        angle=360-angle;
    }
    angle = min(360 - angle, angle);
 
    return angle;
}
int min(int x, int y)
{
    return (x < y)? x: y;
     
}
int main (){
    float h,m,result;
    char rest;
    h=1;
    //scanf("%f%c%f",&h,&rest,&m);
    while (h!=0 || m!=0){
        scanf("%f%c%f",&h,&rest,&m);
        if(h==0 && m==0){
            break;
        }
        else{
        
        result=calcAngle(h,m);
        printf("%.3f\n",result);
        }
    }
    

}
 