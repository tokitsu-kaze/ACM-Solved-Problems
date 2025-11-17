#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> fac[MAX];
void init_fac(int n)
{
	int i,j,mxcnt;
	mxcnt=0;
	for(i=1;i<=n;i++)
	{
		fac[i].clear();
		fac[i].push_back(i);
		for(j=2;j*j<=i;j++)
		{
			if(i%j) continue;
			fac[i].push_back(j);
			if(i/j!=j) fac[i].push_back(i/j);
		}
		mxcnt=max(mxcnt,(int)fac[i].size());
	}
//	printf("%d\n",mxcnt);
}
int cnt[MAX],mx,tot;
void work(int x,int ban)
{
	for(auto &it:fac[x])
	{
		cnt[it]++;
		if(cnt[it]==1) tot++;
		if(it>ban) mx=max(mx,cnt[it]);
	}
}
int main()
{
	init_fac(MAX-10);
	int T,n,i,x,g,preg;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) cnt[i]=0;
		mx=0;
		tot=0;
		vector<int> ans;
		g=0;
		preg=n;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			g=__gcd(g,x);
			while(preg>g) mx=max(mx,cnt[preg--]);
			work(x,g);
			if(fac[x].size()<tot) mx=max(mx,1);
			ans.push_back(mx);
		}
		for(i=0;i<n;i++) printf("%d%c",ans[i]," \n"[i+1==n]);
	}
	return 0;
}
