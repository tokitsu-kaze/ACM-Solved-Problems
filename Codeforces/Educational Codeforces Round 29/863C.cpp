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
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
struct node
{
	ll a,b;
	node(){}
	node(ll x,ll y):a(x),b(y){}
	friend bool operator<(node a,node b)
	{
		if(a.a==b.a) return a.b<b.b;
		return a.a<b.a;
	}
};
ll a[5][5],b[5][5],ans[3];
map<node,ll> mp;
set<node> s;
set<node> ::iterator it;
void judge(ll a,ll b,ll k)
{
	if(a==b) return;
	if(a+b==5||a+b==3) ans[a<b]+=k;
	else ans[a>b]+=k;
}
int main()
{
	ll n,m,k,i,j,t1,t2,cnt,loop,id;
	while(~scanf("%lld%lld%lld",&k,&n,&m))
	{
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				scanf("%lld",&a[i][j]);
			}
		}
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				scanf("%lld",&b[i][j]);
			}
		}
		s.clear();
		mp.clear();
		cnt=1;
		s.insert(node(n,m));
		mp[node(n,m)]=cnt++;
		while(1)
		{
			t1=a[n][m];
			t2=b[n][m];
			ll sz=sz(s);
			s.insert(node(t1,t2));
			if(sz(s)==sz)
			{
				id=mp[node(t1,t2)];
				loop=cnt-id;
				break;
			}
			mp[node(t1,t2)]=cnt++;
			n=t1;
			m=t2;
		}
		mem(ans,0);
		for(it=s.begin();it!=s.end();it++)
		{
			ll temp=k-id+1;
			if(mp[*it]>k) continue;
			if(mp[*it]<id) judge((*it).a,(*it).b,1);
			else judge((*it).a,(*it).b,temp/loop+(mp[*it]-id+1<=temp%loop?1:0));
		}
		printf("%lld %lld\n",ans[0],ans[1]);
	}
	return 0;
}