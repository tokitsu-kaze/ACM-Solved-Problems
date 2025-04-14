#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=35+10;
struct Gauss
{
	static const int N=37;
	bitset<N> mp[N];
	void init()
	{
		for(int i=0;i<N;i++) mp[i].reset();
	}
	int gauss(int n,int m)
	{
		int i,j,k,pos,r;
		r=0;
		for(k=1;k<=m;k++)
		{
			pos=r+1;
			if(pos>n) return -1; // no solution
			while(pos<n&&!mp[pos][k]) pos++;
			if(!mp[pos][k]) continue;
			r++;
			swap(mp[pos],mp[r]);
			for(i=r+1;i<=n;i++)
			{
				if(mp[i][k]) mp[i]^=mp[r];
			}
		}
		return r;
	}
	int res[N],ans;
	void dfs(int x,int m,int now)
	{
		int i;
		if(now>=ans) return;
		if(x==0)
		{
//			printf("%d\n",now);
//			for(i=1;i<=m;i++) printf("%d%c",res[i]," \n"[i==m]);
			ans=min(ans,now);
			return;
		}
		res[x]=mp[x][m+1];
		for(i=x+1;i<=m;i++) res[x]^=(mp[x][i]*res[i]);
		if(mp[x][x]==0)
		{
			if(res[x]) return;
			res[x]=0;
			dfs(x-1,m,now+res[x]);
			res[x]=1;
			dfs(x-1,m,now+res[x]);
			res[x]=0;
		}
		else
		{
			dfs(x-1,m,now+res[x]);
			res[x]=0;
		}
	}
	int work(int n,int m)
	{
		int i,j,cnt;
		cnt=gauss(n,m);
		for(i=1;i<=n;i++)
		{
			if(!mp[i][i])
			{
				for(j=n;j>i;j--) swap(mp[j],mp[j-1]);
			}
		}
		memset(res,0,sizeof res);
		ans=m;
		dfs(m,m,0);
		return ans;
	}
}gs;
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	gs.init();
	while(m--)
	{
		scanf("%d%d",&a,&b);
		gs.mp[a][b]=gs.mp[b][a]=1;
	}
	for(i=1;i<=n;i++)
	{
		gs.mp[i][i]=1;
		gs.mp[i][n+1]=1;
	}
	printf("%d\n",gs.work(n,n));
	return 0;
}
