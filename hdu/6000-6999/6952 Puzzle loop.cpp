#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=998244353;
struct Gauss
{
	static const int N=600;
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
	int work(int n,int m)
	{
		int i,j,cnt;
		cnt=gauss(n,m);
		if(cnt==-1) return 0;
		for(i=cnt+1;i<=n;i++)
		{
			if(mp[i][m+1])
			{
				// no solution
				return 0;
			}
		}
		int res=1;
		for(i=1;i<=m-cnt;i++) res=res*2LL%mod;
		return res;
	}
}gs;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int id[22][22];
char mp[22][22];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T,n,m,i,j,k,tot,x,y;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		n--;
		m--;
		for(i=1;i<=n;i++) cin>>mp[i]+1;
		tot=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				id[i][j]=++tot;
			}
		}
		gs.init();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(mp[i][j]=='.') continue;
				gs.mp[id[i][j]][n*m+1]=mp[i][j]-'0';
				for(k=0;k<4;k++)
				{
					x=i+dir[k][0];
					y=j+dir[k][1];
					if(x<1||x>n||y<1||y>m) continue;
					gs.mp[id[i][j]][id[x][y]]=1;
				}
			}
		}
		cout<<gs.work(n*m,n*m)<<"\n";
	}
	return 0;
}
