#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int b,c;};
int a[MAX],b[MAX],c[MAX];
int main()
{
	int T,n,m,i,j,ans,mx,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=m;i++) scanf("%d",&b[i]);
		for(i=1;i<=m;i++) scanf("%d",&c[i]);
		priority_queue<int,vector<int>,greater<int>> q;
		vector<node> rc;
		vector<int> rb;
		for(i=1;i<=n;i++) q.push(a[i]);
		for(i=1;i<=m;i++)
		{
			if(c[i]>0) rc.push_back({b[i],c[i]});
			else rb.push_back(b[i]);
		}
		sort(rb.begin(),rb.end());
		sort(rc.begin(),rc.end(),[](node x,node y){
			if(x.b==y.b) return x.c<y.c;
			return x.b<y.b;
		});
		mx=0;
		ans=0;
		i=j=0;
		while(!q.empty())
		{
			x=q.top();
			q.pop();
			mx=max(mx,x);
			if(i==rb.size() && j==rc.size()) break;
			if(i==rb.size())
			{
				if(x>=rc[j].b)
				{
					q.push(max(x,rc[j].c));
					j++;
					ans++;
				}
				continue;
			}
			if(j==rc.size())
			{
				if(x>=rb[i])
				{
					ans++;
					i++;
				}
				continue;
			}
			
			if(x>=rb[i])
			{
				ans++;
				i++;
			}
			else if(x>=rc[j].b)
			{
				q.push(max(x,rc[j].c));
				j++;
				ans++;
			}
		}
		for(;j<rc.size();j++)
		{
			if(mx>=rc[j].b)
			{
				ans++;
				mx=max(mx,rc[j].c);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
