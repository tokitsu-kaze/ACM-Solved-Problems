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
const int MAX=2e6+10;
const ll mod=1e9+7;
int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		if(!k||k==n)
		{
			puts("0 0");
			continue;
		}
		printf("1 %d\n",min(k*2,n-k));
	}
	return 0;
}