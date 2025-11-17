#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,x,prex;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		priority_queue<int> q,qx;
		priority_queue<int,vector<int>,greater<int>> nowx;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			q.push(x);
		}
		ans=x=0;
		prex=-INF;
		for(i=1;i<=2*n;i++)
		{
			if(!q.empty() && !qx.empty() && !nowx.empty() &&
				q.top()+x-nowx.top()>=qx.top())
			{
				ans-=nowx.top();
				qx.push(nowx.top());
				nowx.pop();
				ans+=q.top();
				q.pop();
				ans+=x;
				nowx.push(x);
				x++;
				
			}
			else if(!q.empty() && !qx.empty())
			{
				if(q.top()>=qx.top())
				{
					ans+=q.top();
					q.pop();
					qx.push(x);
					x++;
				}
				else
				{
					ans+=qx.top();
					nowx.push(qx.top());
					qx.pop();
				}
			}
			else if(!q.empty())
			{
				ans+=q.top();
				q.pop();
				qx.push(x);
				x++;
			}
			else if(!qx.empty())
			{
				ans+=qx.top();
				nowx.push(qx.top());
				qx.pop();
			}
			printf("%lld%c",ans," \n"[i==2*n]);
		}
	}
	return 0;
}
