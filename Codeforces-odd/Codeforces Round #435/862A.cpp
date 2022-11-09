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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,x,i,a[111],t,ans;
	while(~scanf("%d%d",&n,&x))
	{
		mem(a,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			a[t]++;
		}
		ans=0;
		for(i=0;i<=100;i++)
		{
			if(!a[i])
			{
				if(i!=x) ans++;
				else break;
			}
			if(i==x&&a[i])
			{
				ans++;
				break;
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}