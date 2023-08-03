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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int a,b,i;
	while(~scanf("%d%d",&a,&b))
	{
		i=0;
		while(a<=b)
		{
			a*=3;
			b*=2;
			i++;
		}
		printf("%d\n",i);
	}
	return 0;
}
