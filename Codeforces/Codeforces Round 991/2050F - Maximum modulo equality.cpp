#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct ST_table
{
	#define type int
	static const int N=MAX;
	static const int LOG=21;
	type g[LOG][N];
	int lg[N],bin[LOG];
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		a[0]=0;
		for(i=1;i<=n;i++) g[0][i]=abs(a[i]-a[i-1]);
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				g[j][i]=__gcd(g[j-1][i],g[j-1][i+bin[j-1]]);
			}
		}
	}
	int ask_gcd(int l,int r)
	{
		int t=lg[r-l+1];
		return __gcd(g[t][l],g[t][r-bin[t]+1]);
	}
	#undef type
}rmq;
int a[MAX];
int main()
{
	int T,n,q,i,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		rmq.work(n,a);
		vector<int> res;
		while(q--)
		{
			scanf("%d%d",&l,&r);
			if(l==r) res.push_back(0);
			else res.push_back(rmq.ask_gcd(l+1,r));
		}
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	}
	return 0;
}

