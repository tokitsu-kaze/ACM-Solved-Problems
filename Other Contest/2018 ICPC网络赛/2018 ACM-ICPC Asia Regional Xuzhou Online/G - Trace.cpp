#include<bits/stdc++.h>
using namespace std;

struct node
{
	int t;
	int x;
	int y;
	friend bool operator <(const node &a,const node &b)
	{
		if(a.x!=b.x)
			return a.x<b.x;
		return a.y<b.y;
	}

}arr[100000];
int n;

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&arr[i].x,&arr[i].y);
			arr[i].t=i;
		}
		sort(arr+1,arr+n+1);
		long long ans=0;
		stack<node>st;
		for(int i=1;i<=n;i++)
		{
			while(!st.empty() && st.top().t < arr[i].t)
			{
				st.pop();
			}
			if(st.empty())
			{
				ans+=arr[i].x;
				st.push(arr[i]);
				continue;
			}
			node pre=st.top();
			ans+=arr[i].x-pre.x;
			st.push(arr[i]);
		}
		while(!st.empty())
			st.pop();


		for(int i=n;i>=1;i--)
		{
			while(!st.empty() && st.top().t < arr[i].t)
			{
				st.pop();
			}
			if(st.empty())
			{
				ans+=arr[i].y;
				st.push(arr[i]);
				continue;
			}
			node pre=st.top();
			ans+=arr[i].y-pre.y;
			st.push(arr[i]);
		}
		printf("%lld\n",ans);

	}

}
