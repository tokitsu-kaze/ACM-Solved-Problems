////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-15 17:12:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6127
////Problem Title: 
////Run result: Accept
////Run time:202MS
////Run memory:2880KB
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
const int MAX=5e4+10;
const ll mod=1e9+7;
struct Point
{  
	int x,y;
	ll v;
	double ang;
	Point(){}
	void input()
	{
		scanf("%d%d%I64d",&x,&y,&v);
		ang=atan2(y*1.0,x*1.0);
	}
}p[MAX];
bool operator <(Point a,Point b){return a.ang>b.ang;}
int main()
{
	ll sum,now,ans;
	int t,n,i,j,flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++)
		{
			p[i].input();
			sum+=p[i].v;
		}
		sort(p,p+n);
	//	for(i=0;i<n;i++) cout<<p[i].v<<" "<<p[i].ang<<endl;
		now=0;
		j=0;
		ans=0;
		flag=0;
	//	cout<<sum<<endl;
		for(i=0;i<n;i++)
		{
			if((!j&&!flag)||(j<i&&!flag)) now+=p[i].v;
	//		if(!(p[i].ang<0)&&j==i)
			if(p[i].ang<0)
			{
				flag=1;
				while((p[j+1==n?0:j+1].ang>-PI&&p[j+1==n?0:j+1].ang<p[i].ang)||(p[j+1==n?0:j+1].ang>p[i].ang+PI&&p[j+1==n?0:j+1].ang<PI))
				{
					j=(j+1==n?0:j+1);
					now+=p[j].v;
				}
			}
			else
			{
				while(j+1<n&&p[j+1].ang>p[i].ang-PI)
				{
					j++;
					now+=p[j].v;
				}
			}
	//		cout<<now<<endl;
			ans=max(now*(sum-now),ans);
			now-=p[i].v;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
/*
100
2
1 1 1
1 -1 1
3
1 1 1
1 -1 10
-1 0 100
1
1 1 1
7
-2 0 100
1 2 9
5 2 8
2 1 7

1 -1 10
-3 -3 20
-100 -1 30
3
-1000000000 1 100
-1 0 10
1 1 100000
*/