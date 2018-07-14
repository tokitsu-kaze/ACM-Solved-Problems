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
int pos[111];
int flag[111];
vector<int> p;
void init()
{
	int i,j,cnt=0;
	mem(pos,0);
	p.clear();
	for(i=2;i<=70;i++)
	{
		if(!flag[i])
		{
			p.pb(i);
			pos[i]=cnt++;
			for(j=i+i;j<=70;j+=i)
			{
				flag[j]=1;
			}
		}
	}
//	for(i=0;i<sz(p);i++) cout<<p[i]<<endl;
}
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int mat[22][MAX];
int Gauss(int n,int m)
{  
    int i,j;  
	for(i=1,j=1;i<=n&&j<=m;j++)
	{  
		int k=i;  
		while(k<=n&&!mat[k][j]) k++;
		if(mat[k][j])
		{  
			for(int r=1;r<=m+1;r++)
            {
				swap(mat[i][r],mat[k][r]);  
			}
			for(int r=1;r<=n;r++)
			{
				if(r!=i&&mat[r][j])
				{
					for(k=1;k<=m+1;k++)
					{
						mat[r][k]^=mat[i][k];
					}
				}
			}
			i++;
		}
	}  
    for(j=i;j<=n;j++)
    {
		if(mat[j][m+1]) return -1;
	}
	return m-i+1;
}
int main()
{
	int n,i,j,k,x;
	ll ans;
	init();
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			for(j=0;j<sz(p);j++)
			{
				int now=0;
				while(x%p[j]==0&&x>1)
				{
					now^=1;
					x/=p[j];
				}
				mat[j+1][i]=now;
			}
		}
		for(j=0;j<sz(p);j++)
		{
			mat[j+1][n+1]=0;
		}
		ans=Gauss((int)sz(p),n);
		printf("%lld\n",pow2(2,ans)-1);
	}
	return 0;
}