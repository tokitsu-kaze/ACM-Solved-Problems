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
struct hash_table
{
	ull seed,p;
	ull Hash[26][MAX],tmp[MAX];
	void set(ull _seed,ull _p)
	{
		seed=_seed;
		p=_p;
	}
	void work(char *s,int n)
	{
		ll i,j;
		tmp[0]=1;
		for(i=1;i<=n;i++) tmp[i]=tmp[i-1]*seed;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<26;j++)
			{
				Hash[j][i]=(Hash[j][i-1]*seed+(s[i]-'a'+j)%26);
			}
		}
	}
	ull get(int l,int r,int id)
	{
		return (Hash[id][r]-Hash[id][l-1]*tmp[r-l+1]);	
	}
}ha;
char s[MAX];
int main()
{
	int n,i,q,x,y,len,ans;
	ull tmp;
	while(~scanf("%d",&n))
	{
		scanf("%s",s+1);
		ha.set(19260817,998244353);
		ha.work(s,n);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d",&x,&y,&len);
			ans=INF;
			tmp=ha.get(y,y+len-1,0);
			for(i=0;i<26;i++)
			{
				if(ha.get(x,x+len-1,i)==tmp)
				{
					ans=min(ans,i);
					ans=min(ans,26-i);
				}
			}
			if(ans==INF) ans=-1;
			printf("%d\n",ans);
		}
	}
	return 0;
}