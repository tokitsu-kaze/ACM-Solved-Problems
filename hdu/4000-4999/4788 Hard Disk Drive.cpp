////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-03 12:51:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4788
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1704KB
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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e3+10;
const ll mod=1e9+7;
int main()
{
	ll t,cas=1,cnt1,cnt2;
	double x,y;
	char s[111];
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lf[%s]",&y,&s);
		x=y;
//		cout<<s<<endl;
		printf("Case #%lld: ",cas++);
		if(s[0]=='B')
		{
			puts("0.00%");
			continue;
		}
		else if(s[0]=='K')
		{
			cnt1=3;
			cnt2=10;
		}
		else if(s[0]=='M')
		{
			cnt1=6;
			cnt2=20;
		}
		else if(s[0]=='G')
		{
			cnt1=9;
			cnt2=30;
		}
		else if(s[0]=='T')
		{
			cnt1=12;
			cnt2=40;
		}
		else if(s[0]=='P')
		{
			cnt1=15;
			cnt2=50;
		}
		else if(s[0]=='E')
		{
			cnt1=18;
			cnt2=60;
		}
		else if(s[0]=='Z')
		{
			cnt1=21;
			cnt2=70;
		}
		else if(s[0]=='Y')
		{
			cnt1=24;
			cnt2=80;
		}
		while(cnt2>0)
		{
			if(cnt1>0)
			{
				cnt1--;
				x*=10;
			}
			x/=2;
			cnt2--;
		}
		while(cnt1>0)
		{
			x*=10;
			cnt1--;
		}
		printf("%.2lf%%\n",(1-x/y)*100);
	}
	return 0;
}