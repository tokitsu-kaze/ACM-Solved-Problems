#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,m,i,bit[111],x;
	while(~scanf("%d%d",&n,&m))
	{
		mem(bit,0);
		while(m--)
		{
			scanf("%d",&x);
			x++;
			bit[x]++;
		}
		for(i=1;i<=101;i++) bit[i]+=bit[i-1];
		while(n--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			l++;
			r++;
			printf("%d\n",bit[r]-bit[l-1]);
		}
	}
	return 0;
}