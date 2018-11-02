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
int main()
{
	ll ans;
	for(int i=1;i<=1000;i++)
	{
		for(int j=i+1;i+j<=1000;j++)
		{
			int k=1000-i-j;
			if(k>j&&i*i+j*j==k*k)
			{
				ans=1LL*i*j*k;
				goto end;
			}
		}
	}
	end:;
	printf("%lld\n",ans);
	return 0;
}
/*

31875000

*/