#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=5e5+10;
const ll mod=1e9+7;
struct node
{
	ll v,id;
	node(){}
	node(ll _v,ll _id) :v(_v),id(_id){}
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int l[MAX],r[MAX],a[MAX];
ll d[MAX];
int main()
{
	int n,k,i;
	ll ans;
	node t;
	while(~scanf("%d%d",&k,&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			l[i]=i-1;
			r[i]=i+1;
		}
		l[1]=0;
		r[n-1]=0;
		sort(a+1,a+n+1);
		priority_queue<node> q;
		d[0]=d[n]=0;
		for(i=1;i<n;i++)
		{
			d[i]=a[i+1]-a[i];
			q.push(node(d[i],i));
		}
		ans=0;
		for(i=1;i<=k;i++)
		{
			while(q.top().v!=d[q.top().id]) q.pop();
			t=q.top();
			q.pop();
	//		cout<<t.id<<" "<<l[t.id]<<" "<<r[t.id]<<" "<<t.v<<endl;
			ans+=t.v;
			l[r[r[t.id]]]=t.id;
			r[l[l[t.id]]]=t.id;
			if(l[t.id]&&r[t.id])
			{
				d[t.id]=d[l[t.id]]+d[r[t.id]]-t.v;
				q.push(node(d[t.id],t.id));
			}
			else d[t.id]=INF;
			d[l[t.id]]=d[r[t.id]]=INF;
			l[t.id]=l[l[t.id]];
			r[t.id]=r[r[t.id]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}