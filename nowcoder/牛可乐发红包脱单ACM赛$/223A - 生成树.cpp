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
int main()
{
	int n,i,a,b,ans;
	while(~scanf("%d",&n))
	{
		map<PII,int> mp;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			if(a<b) swap(a,b);
			mp[MP(a,b)]=1;
		}
		ans=0;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			if(a<b) swap(a,b);
			ans+=mp[MP(a,b)];
		}
		printf("%d\n",n-ans-1);
	}
	return 0;
}