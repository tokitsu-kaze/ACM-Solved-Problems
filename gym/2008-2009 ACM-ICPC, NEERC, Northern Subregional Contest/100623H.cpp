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
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	freopen("Holes.in","r",stdin);
	freopen("Holes.out","w",stdout);
	int n;
	while(~scanf("%d",&n))
	{
		if(n<=1)
		{
			printf("%d\n",n^1);
			continue;
		}
		if(n%2)
		{
			printf("4");
			n--;
		}
		n/=2;
		while(n--) printf("8");
		puts("");
	}
	return 0;
}