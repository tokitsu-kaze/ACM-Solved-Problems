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
const int MAX=2e6+10;
const ll mod=1e9+7;
int flag[MAX];
vector<int> p;
void init()
{
	int i,j;
	mem(flag,0);
	p.clear();
	for(i=2;i<=MAX-10;i++)
	{
		if(flag[i]) continue;
		p.pb(i);
		for(j=i+i;j<=MAX-10;j+=i)
		{
			if(!flag[j]) flag[j]=i;
		}
	}
}
int ans[MAX];
vector<int> res;
void work(int x)
{
	int t;
	while(x>1)
	{
		t=flag[x];
		if(!t)
		{
			res.pb(x);
			return;
		}
		while(x%t==0&&x>1) x/=t;
		res.pb(t);
	}
}
int tag[MAX];
int main()
{
	init();
	int n,i,j,x,f,k,now;
	while(~scanf("%d",&n))
	{
		mem(tag,0);
		now=f=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(f)
			{
				while(tag[p[now]]&&now<sz(p)) now++;
				ans[i]=p[now];
				tag[p[now]]=1;
				continue;
			}
			res.clear();
			work(x);
			for(j=0;j<sz(res);j++)
			{
				if(tag[res[j]])
				{
					f=1;
					break;
				}
			}
			if(!f)
			{
				for(j=0;j<sz(res);j++)
				{
					tag[res[j]]=1;
				}
				ans[i]=x;
			}
			else
			{
				for(j=x+1;;j++)
				{
					res.clear();
					work(j);
					int ff=0;
					for(k=0;k<sz(res);k++)
					{
						if(tag[res[k]])
						{
							ff=1;
							break;
						}
					}
					if(!ff)
					{
						ans[i]=j;
						for(k=0;k<sz(res);k++)
						{
							tag[res[k]]=1;
						}
						break;
					}
				}
			}
		}
		for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}