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
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int mp[10010][15][33],a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void init()
{
	int i,j,k,cy,cm,cnt;
	char temp[11];
	mem(mp,0);
	mem(temp,0);
	cnt=0;
	for(i=2000;i<=9999;i++)
	{
		cy=0;
		sprintf(temp,"%d",i);
		for(j=0;j<strlen(temp);j++)
		{
			if(temp[j]=='9') cy++;
		}
		mem(temp,0);
		for(j=1;j<=12;j++)
		{
			cm=0;
			if(j==9) cm=1;
			mem(temp,0);
			if(j==2&&((i%4==0&&i%100!=0)||(i%400==0)))
			{
				for(k=1;k<=a[j]+1;k++)
				{
					cnt+=cy+cm;
					if(k%10==9) cnt++;
					mp[i][j][k]=cnt;
				}
			}
			else
			{
				for(k=1;k<=a[j];k++)
				{
					cnt+=cy+cm;
					if(k%10==9) cnt++;
					mp[i][j][k]=cnt;
				}
			}
		}
	}
//	cout<<cnt<<endl;
}
int main()
{
	int t,y1,m1,d1,y2,m2,d2;
	init();
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d%d%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2);
			if(d1==1)
			{
				if(m1==1)
				{
					m1=12;
					y1--;
				}
				else m1--;
				d1=a[m1];
				if(m1==2&&((y1%4==0&&y1%100!=0)||(y1%400==0))) d1++;
			}
			else d1--;
			printf("%d\n",mp[y2][m2][d2]-mp[y1][m1][d1]);
		}
	}
	return 0;
}