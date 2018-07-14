#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
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
const int MAX=2e5+10;
const ll mod=1e9+7;
struct node
{
	int id,t,idx;
	void input(int i)
	{
		scanf("%d%d",&id,&t);
		idx=i;
	}
	friend bool operator<(node a,node b)
	{
		return a.t>b.t;
	}
}a[MAX];
vector<int> ans;
int n,s;
bool check(int k)
{
	int i,cnt=0;
	priority_queue<node> q;
	for(i=0;i<n;i++)
	{
		if(a[i].id>=k) q.push(a[i]);
	}
	int now=s;
	vector<int> res;
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		if(now<t.t) break;
		now-=t.t;
		cnt++;
		if(sz(res)>=k) continue;
		res.pb(t.idx);
		
	}
	if(sz(res)>=sz(ans)) ans=res;
	if(cnt>=k) return 1; 
	return 0;
}
int main()
{
	int l,r,mid,i;
	while(~scanf("%d%d",&n,&s))
	{
		for(i=0;i<n;i++) a[i].input(i+1);
		l=0;
		r=n;
		ans.clear();
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid)) l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",sz(ans));
		printf("%d\n",sz(ans));
		if(sz(ans))
		{
			printf("%d",ans[0]);
			for(i=1;i<sz(ans);i++) printf(" %d",ans[i]);
		} 
		puts("");
	} 
	return 0;
}