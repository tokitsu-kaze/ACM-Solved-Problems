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
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=2e5+10;
const ll mod=998244353;
struct hash_table
{
	ll seed,p;
	ll Hash[MAX],tmp[MAX];
	void set(ll _seed,ll _p)
	{
		seed=_seed;
		p=_p;
	}
	void work(string s,int n)
	{
		ll i,j;
		tmp[0]=1;
		for(i=1;i<=n;i++) tmp[i]=tmp[i-1]*seed%p;
		for(i=0;i<n;i++) Hash[i+1]=(Hash[i]*seed%p+(s[i]))%p;
	}
	ll get(int l,int r)
	{
		return (Hash[r]-Hash[l-1]*tmp[r-l+1]%p+p)%p;
	}
}h1,h2;
int bit[MAX];
int main()
{
	ll hh1,hh2;
	int n,i,j,k,l,ans,flag,pos,f;
	string s[333],res,tmp;
	srand(time(0));
	while(~scanf("%d",&n))
	{
		ans=0;
		bit[0]=0;
		tmp="";
		for(i=1;i<=n;i++)
		{
			cin>>s[i];
			ans+=s[i].length();
			tmp+=s[i];
			if(i!=n) tmp+=' ';
			bit[i]=bit[i-1]+s[i].length();
			if(i!=1) bit[i]++;
		}
		ans+=n-1;
		h1.set(rand(),1e9+7);
		h1.work(tmp,tmp.length());
		h2.set(rand(),1e9+9);
		h2.work(tmp,tmp.length());
		for(i=1;i<=n;i++)
		{
			for(j=1;j+2*i-1<=n;j++)
			{
				res="";
				f=0;
				for(k=1;k<j;k++)
				{
					f=1;
					res+=s[k];
					if(k!=j-1) res+=' ';
				}
				for(k=j;k<=j+i-1;k++)
				{
					if(f)
					{
						res+=' ';
						f=0;
					}
					res+=s[k][0]-'a'+'A';
				}
				hh1=h1.get(bit[j-1]+(j==1?1:2),bit[j+i-1]);
				hh2=h2.get(bit[j-1]+(j==1?1:2),bit[j+i-1]);
				k=j+i;
				f=1;
				while(k<=n)
				{
					flag=0;
					if(k+i-1>n) flag=1;
					else
					{
						if(h1.get(bit[k-1]+(k==1?1:2),bit[k+i-1])!=hh1) flag=1;
						if(h2.get(bit[k-1]+(k==1?1:2),bit[k+i-1])!=hh2) flag=1;
					}
					if(!flag)
					{
						res+=' ';
						for(pos=k,l=j;pos<=k+i-1&&pos<=n;pos++,l++)
						{
							res+=s[pos][0]-'a'+'A';
						}
						k=k+i;
						f++;
					}
					else
					{
						res+=' ';
						res+=s[k];
						k++;
					}
				}
				if(f==1) continue;
				if(ans>sz(res)) tmp=res;
				ans=min(ans,sz(res));
			}
		}
	//	cout<<tmp<<endl;
		printf("%d\n",ans);
	}
	return 0;
}
/*
5
a a a a a
2
aa aa
*/
