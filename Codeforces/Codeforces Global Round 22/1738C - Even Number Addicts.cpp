#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
int sg[MAX][MAX][2][2];
int dfs(int x,int y,int z,int f)
{
	if(sg[x][y][z][f]!=-1) return sg[x][y][z][f];
	int i,j,flag[105];
	memset(flag,0,sizeof flag);
	if(f==0)
	{
		if(x>0) flag[dfs(x-1,y,z,f^1)]=1;
		if(y>0) flag[dfs(x,y-1,z^1,f^1)]=1;
	}
	else
	{
		if(x>0) flag[dfs(x-1,y,z,f^1)]=1;
		if(y>0) flag[dfs(x,y-1,z,f^1)]=1;
	}
	for(i=0;;i++)
	{
		if(!flag[i])
		{
			j=i;
			break;
		}
	}
//	printf("%d %d %d %d %d\n",x,y,z,f,j);
	return sg[x][y][z][f]=j;
}
int main()
{
	int T,n,i,x,cnt[2];
	memset(sg,-1,sizeof sg);
	sg[0][0][0][0]=1;
	sg[0][0][1][0]=0;
	sg[0][0][0][1]=0;
	sg[0][0][1][1]=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cnt[0]=cnt[1]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x&1]++;
		}
		if(dfs(cnt[0],cnt[1],0,0)) puts("Alice");
		else puts("Bob");
	}
	return 0;
}

