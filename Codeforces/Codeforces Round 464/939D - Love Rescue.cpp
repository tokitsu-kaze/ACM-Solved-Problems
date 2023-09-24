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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int pre[33];
void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		pre[i]=i;
	}
}
int find(int x)
{
	if(pre[x]!=x) pre[x]=find(pre[x]);
	return pre[x];
}
void merge(int a,int b)
{
	int rx,ry;
	rx=find(a);
	ry=find(b);
	if(rx!=ry)
	{
		pre[rx]=ry;
	}
}
char a[MAX],b[MAX];
int main()
{
	int n,i,x,y;
	while(~scanf("%d",&n))
	{
		init(26);
		scanf("%s%s",a,b);
		vector<pair<char,char> > ans;
		for(i=0;i<n;i++)
		{
			x=find(a[i]-'a'+1);
			y=find(b[i]-'a'+1);
			if(x==y) continue;
			ans.pb(MP(a[i],b[i]));
			merge(x,y);
		}
		printf("%d\n",sz(ans));
		for(i=0;i<sz(ans);i++) printf("%c %c\n",ans[i].fi,ans[i].se);
	}
	return 0;
}