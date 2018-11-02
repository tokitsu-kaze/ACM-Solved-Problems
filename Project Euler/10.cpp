#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int p[MAX],tot,prime[MAX];
void init(int n)
{
	int i,j;
	tot=0;
	mem(prime,0);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
        for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
int main()
{
	init(MAX-10);
	ll ans=0;
	for(int i=0;i<tot;i++) ans+=p[i];
	printf("%lld\n",ans);
	return 0;
}
/*

142913828922

*/