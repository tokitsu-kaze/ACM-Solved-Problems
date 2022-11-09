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
const ll mod=1e9+7;
int ans[MAX],a[MAX];
set<int> s;
int main()
{
	int n,q,i,x;
	while(~scanf("%d%d",&n,&q))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		s.clear();
		for(i=n;i>=1;i--)
		{
			s.insert(a[i]);
			ans[i]=(int)sz(s);
		}
		while(q--)
		{
			scanf("%d",&x);
			printf("%d\n",ans[x]);
		}
	}
	return 0;
}