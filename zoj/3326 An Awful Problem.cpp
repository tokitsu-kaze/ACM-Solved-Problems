#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int a[3011][13][32];
int main()
{
	int cnt=0,t;
    int m[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int pre[]= {0,2,3,5,7,11,13,17,19,23,29,31};
    mem(a,0);
    for(int i=1000;i<=3000;i++)
    {
        if((i%4==0&&i%100!=0)||i%400==0) m[2]=29;
        for(int j=1;j<=12;j++)
        {
            for(int k=1; k<=m[j]; k++)
            {
                if((j==2||j==3||j==5||j==7||j==11)&&(k==2||k==3||k==5||k==7||k==11||k==13||k==17||k==19||k==23||k==29||k==31))
                cnt++;
                a[i][j][k]=cnt;
            }
        }
        m[2]=28;
    }
    while(~scanf("%d",&t))
    {
		while(t--)
	    {
	        int y1,m1,d1,y2,m2,d2;
	        scanf("%d%d%d%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2);
	        if(d1==1&&m1==1)
	        {
	            y1--;
	            m1=12;
	            d1=31;
	        }
	        else if(d1==1&&m1!=1)
	        {
	            if((y1%4==0&&y1%100!=0)||y1%400==0)
	            {
	                m[2]=29;
	            }
	            m1=m1-1;
	            d1=m[m1];
	        }
	        else d1=d1-1;
	        printf("%d\n",a[y2][m2][d2]-a[y1][m1][d1]);
	    }
	}
}