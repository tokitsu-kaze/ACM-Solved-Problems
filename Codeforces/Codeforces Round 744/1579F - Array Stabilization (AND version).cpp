#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int a[MAX];
int main()
{
	int T,n,d,i,sz,ans,x,nex;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&d);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		queue<int> q;
		for(i=0;i<n;i++)
		{
			if(a[i]==0) q.push(i);
		}
		ans=0;
		while(!q.empty())
		{
			ans++;
			sz=q.size();
			while(sz--)
			{
				x=q.front();
				q.pop();
				nex=(x+d)%n;
				if(a[nex]==0) continue;
				a[nex]=0;
				q.push(nex);
			}
		}
		ans--;
		for(i=0;i<n;i++)
		{
			if(a[i]) ans=-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
