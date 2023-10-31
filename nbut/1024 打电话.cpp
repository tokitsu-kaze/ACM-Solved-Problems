#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int len,i,x1,x2,y1,y2;
    double d;
    char a[201];
    while(~scanf("%s",a))
    {
		d=0;
		len=strlen(a);
		x1=y1=2;
		for(i=0;i<len;i++)
		{
			switch(a[i])
			{
				case '1':x2=1,y2=1;break;
				case '2':x2=2,y2=1;break;
				case '3':x2=3,y2=1;break;
				case '4':x2=1,y2=2;break;
				case '5':x2=2,y2=2;break;
				case '6':x2=3,y2=2;break;
				case '7':x2=1,y2=3;break;
				case '8':x2=2,y2=3;break;
				case '9':x2=3,y2=3;break;
				case '0':x2=2,y2=4;break;
			}
			d=d+sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
			x1=x2;
			y1=y2;
		}
		printf("%.6lf\n",d);
    }
    return 0;
}