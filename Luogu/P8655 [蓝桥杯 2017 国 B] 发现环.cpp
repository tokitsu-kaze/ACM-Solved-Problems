#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
vector<int> mp[MAX],circle;
int top,st[MAX],flag[MAX];
void dfs(int x,int fa)
{
	st[top++]=x;
	flag[x]=2;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		if(flag[to]==2)
		{
			for(int i=top-1;;i--)
			{
				circle.push_back(st[i]);
				if(st[i]==to) break;
			}
		}
		else if(!flag[to]) dfs(to,x);
	}
	top--;
	flag[x]=1;
}
int main()
{
	int n,i,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		flag[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	top=0;
	circle.clear();
	dfs(1,0);
	sort(circle.begin(),circle.end());
	for(i=0;i<circle.size();i++)
	{
		printf("%d%c",circle[i]," \n"[i+1==circle.size()]);
	}
	return 0;
}
