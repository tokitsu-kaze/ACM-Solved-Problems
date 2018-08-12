#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    while(~scanf("%d",&t))
    {
	    while(t--)
	    {
	        double a,b,c,d,e,f;
	        scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
	        if ( a == c && d*d + e*e - 4*a*f > 0 )
	        {
	            printf("circle\n");
	            continue;
	        }
	        if ( a == 0 && c!=0 && d!=0 || c == 0 && a!=0 && e!=0 )
	        {
	            printf("parabola\n");
	            continue;
	        }
	
	        if ( a>0 && c<0 || a<0 && c>0 )
	        {
	            printf("hyperbola\n");
	        }
	        else{
	            printf("ellipse\n");
	        }
	
		    }
	}
}