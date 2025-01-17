#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
int a[MAX],q[MAX],vis[MAX];
int main()
{
	int T,n,m,k,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=m;i++) scanf("%d",&a[i]);
		for(i=1;i<=k;i++) scanf("%d",&q[i]);
		for(i=1;i<=n;i++) vis[i]=0;
		string res;
		if(k==n)
		{
			for(i=1;i<=m;i++) res+="1";
		}
		else if(k<n-1)
		{
			for(i=1;i<=m;i++) res+="0";
		}
		else
		{
			for(i=1;i<=k;i++) vis[q[i]]=1;
			for(i=1;i<=m;i++)
			{
				if(!vis[a[i]]) res+="1";
				else res+="0";
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
