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
const int MAX=5e5+10;
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
		if(prime[i]) continue;
		p[tot++]=i;
		for(j=i;j<=n;j+=i)
		{
			if(!prime[j]) prime[j]=i;
		}
	}
}
int main()
{
	init(MAX-10);
	printf("%d\n",p[10000]);
	return 0;
}
/*

104743

*/