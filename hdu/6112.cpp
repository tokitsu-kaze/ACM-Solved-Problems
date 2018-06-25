////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-12 18:27:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6112
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1716KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int bit[10010];
bool check(int x)
{
    if((x%400==0)||(x%4==0&&x%100!=0)) return 1;
    return 0;
}
void init()
{
	int i;
	mem(bit,0);
	for(i=1;i<=9999;i++)
	{
		bit[i]=bit[i-1]+365;
		if(check(i)) bit[i]++;
	}
}
int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	init();
	int t,i,y,m,d,now,temp,temp2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d-%d-%d",&y,&m,&d);
		now=bit[y-1];
		temp2=0;
		for(i=1;i<m;i++)
		{
			temp2+=a[i];
		}
		temp2+=d;
		if(check(y)&&m>2) now++;
		now+=temp2;
		for(i=y;;i++)
		{
			temp=bit[i]+temp2;
			if(check(i+1)&&m>2) temp++;
			if(m==2&&d==29)
			{
				if(temp%7==now%7&&check(i+1))
				{
					printf("%d\n",i+1);
					break;
				}
			}
			else if(temp%7==now%7)
			{
				printf("%d\n",i+1);
				break;
			}
		}
	}
	return 0;
}
/*
100
6666-06-06
*/