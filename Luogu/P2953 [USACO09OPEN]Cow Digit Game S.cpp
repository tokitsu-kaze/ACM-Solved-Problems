#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
const int INF=0x3f3f3f3f;
int sg[MAX];
int dfs(int x)
{
	int i,j,flag[5];
	if(sg[x]!=-1) return sg[x];
	memset(flag,0,sizeof flag);
	string tmp=to_string(x);
	int mn=INF;
	int mx=-INF;
	for(auto &it:tmp)
	{
		if(it=='0') continue;
		mn=min(mn,it-'0');
		mx=max(mx,it-'0');
	}
	if(mn!=INF) flag[dfs(x-mn)]=1;
	if(mx!=-INF) flag[dfs(x-mx)]=1;
	for(i=0;;i++)
	{
		if(!flag[i])
		{
			j=i;
			break;
		}
	}
	return sg[x]=j;
}
int main()
{
	int t,x;
	memset(sg,-1,sizeof sg);
	sg[0]=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		if(dfs(x)) puts("YES");
		else puts("NO");
	}
	return 0;
}

