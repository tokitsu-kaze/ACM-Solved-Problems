#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int sg[MAX][21];
char s[MAX];
vector<int> mp[MAX];
int dfs(int x,int k)
{
	if(sg[x][k]!=-1) return sg[x][k];
	if(k==0)
	{
		if(s[x]=='A') sg[x][k]=1;
		else sg[x][k]=0;
		return sg[x][k];
	}
	int i,j;
	map<int,int> flag;
	for(auto &to:mp[x])
	{
		flag[dfs(to,k-1)]=1;
	}
	for(i=0;;i++)
	{
		if(!flag.count(i))
		{
			j=i;
			break;
		}
	}
	return sg[x][k]=j;
}
int main()
{
	int T,n,m,k,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		scanf("%s",s+1);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			memset(sg[i],-1,sizeof sg[i]);
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
		}
		if(dfs(1,2*k)) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
