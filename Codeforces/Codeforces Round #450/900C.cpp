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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int pos[MAX],cnt[MAX];
int bit[MAX];
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int v)
{
	while(x<=MAX-10)
	{
		bit[x]+=v;
		x+=lowbit(x);
	}
}
int getsum(int x)
{
	int res=0;
	while(x)
	{
		res+=bit[x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	int n,i,x;
	while(~scanf("%d",&n))
	{
		mem(cnt,0);
		mem(bit,0);
		set<int> s;
		set<int> ::iterator it;
		s.insert(INF);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			it=s.lower_bound(x);
			if(getsum(x)==i-1) cnt[x]--;
			else if(getsum(x)==i-2&&*it!=INF) cnt[*it]++;
			s.insert(x);
			update(x,1);
		}
		int maxx=-1;
		for(i=1;i<=n;i++)
		{
			maxx=max(maxx,cnt[i]);
		}
		for(i=1;i<=n;i++)
		{
			if(cnt[i]==maxx)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}