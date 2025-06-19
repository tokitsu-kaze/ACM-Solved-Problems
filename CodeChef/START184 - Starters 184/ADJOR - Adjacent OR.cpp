#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int a[MAX],b[MAX];
int main()
{
	int T,n,i,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		if(a[1]!=b[1] || a[n]!=b[n])
		{
			puts("No");
			continue;
		}
		set<int> s;
		queue<int> q;
		for(i=1;i<=n;i++)
		{
			if(a[i]==1 && b[i]==0)
			{
				if(a[i-1]==0 && a[i+1]==0) q.push(i);
				else s.insert(i);
			}
		}
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			a[x]=0;
			if(s.size()==0) continue;
			auto it=s.lower_bound(x);
			if(it!=s.end())
			{
				y=*it;
				if(a[y-1]==0 && a[y+1]==0)
				{
					s.erase(it);
					q.push(y);
				}
			}
			it=s.lower_bound(x);
			if(it!=s.begin())
			{
				it--;
				y=*it;
				if(a[y-1]==0 && a[y+1]==0)
				{
					s.erase(it);
					q.push(y);
				}
			}
		}
		if(s.size())
		{
			puts("No");
			continue;
		}
		
		s.clear();
		while(!q.empty()) q.pop();
		for(i=1;i<=n;i++)
		{
			if(a[i]==0 && b[i]==1)
			{
				if(a[i-1]==1 || a[i+1]==1) q.push(i);
				else s.insert(i);
			}
		}
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			a[x]=1;
			if(s.size()==0) continue;
			auto it=s.lower_bound(x);
			if(it!=s.end())
			{
				y=*it;
				if(a[y-1]==1 || a[y+1]==1)
				{
					s.erase(it);
					q.push(y);
				}
			}
			it=s.lower_bound(x);
			if(it!=s.begin())
			{
				it--;
				y=*it;
				if(a[y-1]==1 || a[y+1]==1)
				{
					s.erase(it);
					q.push(y);
				}
			}
		}
		if(s.size())
		{
			puts("No");
			continue;
		}
		puts("Yes");
	}
	return 0;
}

