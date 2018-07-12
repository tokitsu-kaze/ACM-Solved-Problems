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
const int MAX=2e5+10;
const ll mod=1e9+7;
struct hash_table
{
	ll seed,p;
	ll Hash[26][MAX],tmp[MAX];
	void set(ll _seed,ll _p)
	{
		seed=_seed;
		p=_p;
	}
	void work(char *s,int n)
	{
		ll i,j;
		tmp[0]=1;
		for(i=1;i<=n;i++) tmp[i]=tmp[i-1]*seed%p;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<26;j++)
			{
				Hash[j][i]=(Hash[j][i-1]*seed%p+((s[i]-'a')==j))%p;
			}
		}
	}
	ll get(int l,int r,int id)
	{
		return (Hash[id][r]-Hash[id][l-1]*tmp[r-l+1]%p+p)%p;	
	}
}a,b;
int check1(int l,int r,int len)
{
	ll ra[33],rb[33],i;
	for(i=0;i<26;i++)
	{
		ra[i]=a.get(l,l+len-1,i);
		rb[i]=a.get(r,r+len-1,i);
	}
	sort(ra,ra+26);
	sort(rb,rb+26);
	for(i=0;i<26;i++)
	{
		if(ra[i]!=rb[i]) return 0;
	}
	return 1;
}
int check2(int l,int r,int len)
{
	ll ra[33],rb[33],i;
	for(i=0;i<26;i++)
	{
		ra[i]=b.get(l,l+len-1,i);
		rb[i]=b.get(r,r+len-1,i);
	}
	sort(ra,ra+26);
	sort(rb,rb+26);
	for(i=0;i<26;i++)
	{
		if(ra[i]!=rb[i]) return 0;
	}
	return 1;
}
char s[MAX];
int main()
{
	int n,m,l,r,len;
	while(~scanf("%d%d",&n,&m))
	{
		scanf("%s",s+1);
		a.set(23333333,1e9+7);
		b.set(19260817,998244353);
		a.work(s,strlen(s+1));
		b.work(s,strlen(s+1));
		while(m--)
		{
			scanf("%d%d%d",&l,&r,&len);
			check1(l,r,len)&&check2(l,r,len)?puts("YES"):puts("NO");
		}
	}
	return 0;
}