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
const int MAX=1e6+10;
const ll mod=1e9+7;
/*
0 0 0
0 0 0
4 5 0
*/
bool flagr[MAX],flagc[MAX];
int main()
{
	ll n,q,x,i,ans,sr,sc,cntr,cntc;
	char op[11];
//	freopen("adjustment.in","r",stdin);
//	freopen("adjustment.out","w",stdout);
	while(~scanf("%lld%lld",&n,&q))
	{
		mem(flagr,0);
		mem(flagc,0);
		cntr=cntc=sr=sc=0;
		while(q--)
		{
			scanf("%s %lld",op,&x);
			if(op[0]=='R')
			{
				if(flagr[x]) ans=0;
				else
				{
					ans=(x+1+x+n)*n/2;
					ans-=sc;
					ans-=cntc*x;
				}
				printf("%lld\n",ans);
				if(!flagr[x]) sr+=x,cntr++;
				flagr[x]=1;
			}
			else
			{
				if(flagc[x]) ans=0;
				else
				{
					ans=(x+1+x+n)*n/2;
					ans-=sr;
					ans-=cntr*x;
				}
				printf("%lld\n",ans);
				if(!flagc[x]) sc+=x,cntc++;
				flagc[x]=1;
			}
		}
	}
	return 0;
}
// gym 100851A
