#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
int main()
{
	int ans=0;
	for(int i=999;i>=100;i--)
	{
		for(int j=999;j>=100;j--)
		{
			string res=to_string(i*j);
			string tmp=res;
			reverse(all(tmp));
			if(res==tmp) ans=max(ans,i*j);
		}
	}
	printf("%d\n",ans);
}
/*

906609

*/