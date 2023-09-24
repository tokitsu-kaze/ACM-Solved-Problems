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
const int MAX=2e5+10;
const ll mod=1e9+7;
struct node
{
	int pos,v;
	node(){}
	node(int a,int b)
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
int main()
{
	int n,i,l,r,cnt;
	while(~scanf("%d",&n))
	{
		v.clear();
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&l,&r);
			v.pb(node(l,1));
			v.pb(node(r+1,-1));
		}
		sort(v.begin(),v.end());
		cnt=0;
		for(i=0;i<sz(v);i++)
		{
			cnt+=v[i].v;
			if(cnt>2) break;
		}
		if(cnt>2) puts("NO");
		else puts("YES");
	}
	return 0;
}