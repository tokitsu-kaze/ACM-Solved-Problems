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
const int MAX=2e5+10;
const ll mod=1e9+7;
int a[MAX],bit[MAX],q[MAX],top,p,flag[MAX];
int main()
{
	int n,i,t,ans;
	while(~scanf("%d",&n))
	{
		mem(bit,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			bit[a[i]]++;
		}
		ans=0;
		top=0;
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			if(!bit[i])
			{
				ans++;
				q[top++]=i;
			}
		}
		sort(q,q+top);
		p=0;
		for(i=1;i<=n;i++)
		{
			if(bit[a[i]]>1)
			{
				if(q[p]<a[i]||flag[a[i]])
				{
					bit[a[i]]--;
					a[i]=q[p++];
				}
				else flag[a[i]]++;
			}
			if(p==top) break;
		}
		printf("%d\n",ans);
		printf("%d",a[1]);
		for(i=2;i<=n;i++)
		{
			printf(" %d",a[i]);
		}
		puts("");
	}
	return 0;
}