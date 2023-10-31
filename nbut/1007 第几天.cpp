#include <stdio.h>
int main()
{
    int n,y,m,d,x,i;
    while(~scanf("%d",&n))
    {
		while(n--)
		{
			scanf("%d%d%d",&y,&m,&d);
			x=0;
        	switch(m)
        	{
        	    case 1:x=d;break;
        	    case 2:x=31+d;break;
        	    case 3:x=59+d;break;
        	    case 4:x=90+d;break;
       		    case 5:x=120+d;break;
       	    	case 6:x=151+d;break;
            	case 7:x=181+d;break;
            	case 8:x=212+d;break;
            	case 9:x=243+d;break;
            	case 10:x=273+d;break;
            	case 11:x=304+d;break;
            	case 12:x=334+d;break;
        	}
        	for(i=1;i<y;i++)
        	{
        		if((i%4==0&&i%100!=0)||(i%400==0)) x++;
			}
			if((y%4==0&&y%100!=0)||(y%400==0))
			{
				if(m>=3) x++;
			}
			x=x+365*(y-1);
			printf("%d\n",x);
		}
    }
    return 0;
}