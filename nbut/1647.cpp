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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;

int main()
{
	int t,temp,a,num[10010],i,j,k,cnt;
	char n[6];
	mem(num,0);
	for(i=1;i<=100;i++)
	{
		num[i*i]=1;
	}
	while(cin>>t)
	{
		getchar();
		k=1;
		while(t--)
		{
			cin>>n;
			cnt=0;
			for(i=0;i<4;i++)
			{
				for(j=0;j<=9;j++)
				{
					if(i==0&&j==0) continue;
					if(j+'0'==n[i]) continue;
					if(i==0)
					{
						temp=j*1000+(n[1]-'0')*100+(n[2]-'0')*10+(n[3]-'0');
					}
					else if(i==1)
					{
						temp=(n[0]-'0')*1000+j*100+(n[2]-'0')*10+(n[3]-'0');
					}
					else if(i==2)
					{
						temp=(n[0]-'0')*1000+(n[1]-'0')*100+j*10+(n[3]-'0');
					}
					else if(i==3)
					{
						temp=(n[0]-'0')*1000+(n[1]-'0')*100+(n[2]-'0')*10+j;	
					}
					if(num[temp]) cnt++;
				}
			}
			printf("Case %d: %d\n",k++,cnt);
		}
	}
    return 0;
}