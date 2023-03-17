#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=10007;
int main()
{
	int n,k,t;
	while(~scanf("%d%d%d",&n,&k,&t))
	{
		t%=(n+k+1);
		if(t<=k) printf("%d\n",t);
		else if(t>k&&t<=n) printf("%d\n",k);
		else printf("%d\n",k-(t-n));
	}
	return 0;
}