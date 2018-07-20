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
const int MAX=3e6+10;
const ll mod=1e9+7;
bool flag[MAX];
int main()
{
	int a,b,c,d;
	while(~scanf("%d%d%d%d",&a,&b,&c,&d))
	{
		while(b<MAX)
		{
			flag[b]=1;
			b+=a;
		}
		while(d<MAX)
		{
			if(flag[d]) break;
			d+=c;
		}
		if(flag[d]) printf("%d\n",d);
		else puts("-1");
	}
	return 0;
}