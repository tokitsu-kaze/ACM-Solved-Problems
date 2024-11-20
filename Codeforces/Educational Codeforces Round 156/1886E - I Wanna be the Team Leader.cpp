#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX],b[22],ida[MAX],nex[22][MAX];
vector<int> ans[22];
int dp[(1<<20)+10],pre[(1<<20)+10];
int main()
{
	int n,m,i,j,k,ok,x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		ida[i]=i;
	}
	sort(ida,ida+n,[](int x,int y){
		return a[x]>a[y];
	});
	for(i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		ans[i].clear();
		for(j=0,k=0;j<n;j++)
		{
			k=max(k,j);
			while(k<n && (k-j+1)*a[ida[k]]<b[i]) k++;
			nex[i][j]=k;
		}
	}
	for(i=0;i<(1<<m);i++)
	{
		dp[i]=INF;
		pre[i]=0;
	}
	dp[0]=0;
	for(i=1;i<(1<<m);i++)
	{
		for(j=0;j<m;j++)
		{
			if(!((i>>j)&1)) continue;
			if(dp[i^(1<<j)]>=n) continue;
			if(dp[i]>nex[j][dp[i^(1<<j)]]+1)
			{
				dp[i]=nex[j][dp[i^(1<<j)]]+1;
				pre[i]=i^(1<<j);
			}
		}
	}
	if(dp[(1<<m)-1]>n) return 0*puts("NO");
	x=(1<<m)-1;
	while(x)
	{
		y=pre[x];
//		cout<<x<<" "<<y<<endl;
//		cout<<dp[x]<<" "<<dp[y]<<endl;
		j=0;
		while((1<<j)!=(x^y)) j++;
		for(i=dp[y];i<dp[x];i++) ans[j].push_back(ida[i]);
		x=y;
	}
	puts("YES");
	for(i=0;i<m;i++)
	{
		printf("%d",(int)ans[i].size());
		for(auto &it:ans[i]) printf(" %d",it+1);
		puts("");
	}
	return 0;
}

