#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,j,ans,a[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=INF;
		for(i=1;i<=n;i++)
		{
			set<int> s;
			for(j=i;j<=n;j++)
			{
				s.insert(a[j]);
				if(s.size()==2)
				{
					ans=min(ans,j-i+1);
					break;
				}
			}
		}
		if(ans==INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
