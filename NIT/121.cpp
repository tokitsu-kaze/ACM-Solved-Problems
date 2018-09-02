#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;
int main()
{
    int n,y,m,d,x,i;
    while(cin>>n)
    {
		while(n--)
		{
			cin>>y>>m>>d;
			if(y<=0||m<=0||d<=0)
			{
				cout<<"buhefa"<<endl;
				continue;
			}
			if(m>12)
			{
				cout<<"buhefa"<<endl;
				continue;
			}
			if((y%4==0&&y%100!=0)||(y%400==0))
			{
				if((m==1&&d>31)||(m==2&&d>29)||(m==3&&d>31)||(m==4&&d>30)||(m==5&&d>31)||(m==6&&d>30)||(m==7&&d>31)||(m==8&&d>31)||(m==9&&d>30)||(m==10&&d>31)||(m==11&&d>30)||(m==12&&d>31))
				{
					cout<<"buhefa"<<endl;
					continue;
				}
			}
			else if((m==1&&d>31)||(m==2&&d>28)||(m==3&&d>31)||(m==4&&d>30)||(m==5&&d>31)||(m==6&&d>30)||(m==7&&d>31)||(m==8&&d>31)||(m==9&&d>30)||(m==10&&d>31)||(m==11&&d>30)||(m==12&&d>31))
			{
				cout<<"buhefa"<<endl;
				continue;
			}
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
			switch(x%7)
			{
				case 1:cout<<"Monday"<<endl;break;
				case 2:cout<<"Tuesday"<<endl;break;
				case 3:cout<<"Wednesday"<<endl;break;
				case 4:cout<<"Thursday"<<endl;break;
				case 5:cout<<"Friday"<<endl;break;
				case 6:cout<<"Saturday"<<endl;break;
				case 0:cout<<"Sunday"<<endl;break;
			}
		}
    }
    return 0;
}