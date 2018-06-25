////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-03 21:04:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6180
////Problem Title: 
////Run result: Accept
////Run time:904MS
////Run memory:6836KB
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
typedef unsigned long long ull;
typedef long double db;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	ll pos,v;
	node(){}
	node(ll a,ll b)
	{
		pos=a;
		v=b;
	}
	friend bool operator<(node a,node b)
	{
		if(a.pos==b.pos) return a.v<b.v;
		return a.pos<b.pos;
	}
};
vector<node> v;
ll l[MAX],r[MAX];
int main()
{
	ll n,i,a,b,cnt,t,now,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		v.clear();
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&a,&b);
			v.pb(node(a,1));
			v.pb(node(b,-1));
		}
		sort(v.begin(),v.end());
		cnt=now=0;
		for(i=0;i<sz(v);i++)
		{
			now+=v[i].v;
			if(now>cnt)
			{
				l[cnt]=v[i].pos;
				r[cnt]=v[i].pos;
				cnt=now;
			}
			else if(v[i].v==-1) r[now]=v[i].pos;
		}
		ans=0;
		for(i=0;i<cnt;i++)
		{
	//		cout<<l[i]<<" "<<r[i]<<endl;
			ans+=r[i]-l[i];
		}
		printf("%lld %lld\n",cnt,ans);
	}
	return 0;
}
/*
10000
3
1 5
2 6
8 10
*/