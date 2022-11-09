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
const int MAX=1e5+10;
const ll mod=1e9+7;
int pre[MAX],w[MAX];
int find(int x)
{
	if(pre[x]==x) return pre[x];
	int t=pre[x];
	pre[x]=find(pre[x]);
	w[x]=(w[x]+w[t])%2;
	return pre[x];
}
void merge(int a,int b,int x)
{
	int ra,rb;
	ra=find(a);
	rb=find(b);
	if(ra!=rb)
	{
		pre[ra]=rb;
		w[ra]=(2-w[a]+w[b]+x)%2;
		puts("YES");
	}
	else
	{
		if((2-w[a]+w[b]+x)%2!=w[ra]) puts("NO");
		else puts("YES");
	}
}
int main()
{
	int i,n,m,q,x,y;
	char s[33],a[33],b[33];
	while(~scanf("%d%d%d",&n,&m,&q))
	{
		hash_map<string,int,str_hash> mp;
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			mp[s]=i;
			pre[i]=i;
			w[i]=0;
		}
		while(m--)
		{
			scanf("%d%s%s",&x,a,b);
			x--;
			merge(mp[a],mp[b],x);
		}
		while(q--)
		{
			scanf("%s%s",a,b);
			int ra,rb;
			x=mp[a];
			y=mp[b];
			ra=find(x);
			rb=find(y);
			if(ra!=rb) puts("3");
			else printf("%d\n",(2-w[x]+w[y])%2+1);
		}
	}
	return 0;
}