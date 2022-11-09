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
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int s,e,c,id,now;
	friend bool operator <(node a,node b)
	{
		return a.e-a.now-a.c>b.e-b.now-b.c;
	}
	void input(int i)
	{
		id=i;
		scanf("%d%d%d",&s,&e,&c);
	}
}a[111];
int main()
{
	int n,m,i,j,k,flag[111],f;
	node t;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=m;i++) a[i].input(i);
		vector<int> res;
		priority_queue<node> q[2];
		vector<node> que;
		mem(flag,0);
		f=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(flag[j]) continue;
				if(a[j].s==i)
				{
					a[j].now=i;
					q[f].push(a[j]);
					flag[j]=1;
				}
			}
			int tag=0;
			for(j=0;j<sz(que);j++)
			{
				if(que[j].e==i)
				{
					tag=1;
					res.pb(m+1);
				}
			}
			if(!tag)
			{
				if(q[f].empty())
				{
					res.pb(0);
					continue;
				}
				t=q[f].top();
				q[f].pop();
				res.pb(t.id);
				t.c--;
				q[f].push(t);
			}	
			while(!q[f].empty())
			{
				t=q[f].top();
				q[f].pop();
				t.now++;
				if(t.c==0)
				{
					que.pb(t);
					continue;
				}
				if(t.e==i+1)
				{
					puts("-1");
					goto end;
				}
	//			cout<<i<<" "<<t.e<<" "<<t.c<<endl;
				q[f^1].push(t);
			}
			f^=1;
		}
		for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i==n-1]);
		end:;
	}
	return 0;
}