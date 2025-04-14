#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int l[MAX],r[MAX],x[MAX],v[MAX];
int main()
{
	int T,n,m,L,i,j,ans;
	ll now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&L);
		for(i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
		for(i=1;i<=m;i++) scanf("%d%d",&x[i],&v[i]);
		now=1;
		ans=0;
		priority_queue<int> q;
		for(i=1,j=0;i<=n;i++)
		{
			while(j+1<=m && x[j+1]<l[i])
			{
				j++;
				q.push(v[j]);
			}
			while(now<r[i]-l[i]+2 && !q.empty())
			{
				now+=q.top();
				q.pop();
				ans++;
			}
			if(now<r[i]-l[i]+2)
			{
				ans=-1;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

