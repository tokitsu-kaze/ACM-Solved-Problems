////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-18 13:49:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6213
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1700KB
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
const long double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int t;
	scanf("%d",&t);
	char a[111],b[111];
	map<string,int> mp;
	mp["rat"]=1;
	mp["ox"]=2;
	mp["tiger"]=3;
	mp["rabbit"]=4;
	mp["dragon"]=5;
	mp["snake"]=6;
	mp["horse"]=7;
	mp["sheep"]=8;
	mp["monkey"]=9;
	mp["rooster"]=10;
	mp["dog"]=11;
	mp["pig"]=12;
	while(t--)
	{
		scanf("%s%s",a,b);
		int ans=mp[b]-mp[a];
		ans=(ans+12)%12;
		if(ans==0) ans=12;
		printf("%d\n",ans);
	}
	return 0;
}