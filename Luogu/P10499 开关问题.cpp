#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=35+10;
struct Gauss
{
	static const int N=31;
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
		if(cnt==-1) return -1;
		for(i=cnt+1;i<=n;i++)
		{
			if(mp[i][m+1])
			{
				// no solution
				return -1;
			}
		}
		return m-cnt;
	}
}gs;
int main()
{
	int T,n,i,a,b,x,res;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		gs.init();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			gs.mp[i][n+1]=x;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x) gs.mp[i].flip(n+1);
		}
		while(~scanf("%d%d",&a,&b))
		{
			if(a==0 && b==0) break;
			gs.mp[b][a]=1;
		}
		for(i=1;i<=n;i++) gs.mp[i][i]=1;
		res=gs.work(n,n);
		if(res==-1) puts("Oh,it's impossible~!!");
		else printf("%d\n",1<<res);
	}
	return 0;
}
