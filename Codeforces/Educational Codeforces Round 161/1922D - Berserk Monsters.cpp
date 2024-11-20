#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
int a[MAX],d[MAX],l[MAX],r[MAX];
bool flag[MAX];
int main()
{
	int t,n,i,now,ans,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&d[i]);
		for(i=0;i<=n+1;i++)
		{
			l[i]=i-1;
			r[i]=i+1;
			flag[i]=0;
		}
		l[0]=0;
		r[n+1]=n+1;
		a[0]=a[n+1]=0;
		queue<int> q;
		for(i=1;i<=n;i++)
		{
			now=0;
			if(i-1>=1) now+=a[i-1];
			if(i+1<=n) now+=a[i+1];
			if(now>d[i])
			{
				q.push(i);
				flag[i]=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			ans=q.size();
			printf("%d%c",ans," \n"[i==n]);
			vector<int> res;
			while(ans--)
			{
				x=q.front();
				q.pop();
				r[l[x]]=r[x];
				l[r[x]]=l[x];
				res.push_back(l[x]);
				res.push_back(r[x]);
			}
			for(auto &it:res)
			{
				if(it>=1 && it<=n && !flag[it])
				{
					if(a[l[it]]+a[r[it]]>d[it])
					{
						q.push(it);
						flag[it]=1;
					}
				}
			}
		}
	}
	return 0;
}
