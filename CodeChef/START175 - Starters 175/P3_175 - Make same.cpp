#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int main()
{
	int T,n,i,j,sumcnt[2],cnt[3][2],ans,now,x,y;
	char s[3][12];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(sumcnt,0,sizeof sumcnt);
		for(i=0;i<3;i++)
		{
			scanf("%s",s[i]+1);
			memset(cnt[i],0,sizeof cnt[i]);
			for(j=1;j<=n;j++) cnt[i][s[i][j]-'0']++;
			sumcnt[0]+=cnt[i][0];
			sumcnt[1]+=cnt[i][1];
		}
		if(sumcnt[0]%n || sumcnt[1]%n)
		{
			puts("-1");
			continue;
		}
		x=sumcnt[0]/n;
		y=sumcnt[1]/n;
		vector<int> id={0,1,2};
		ans=INF;
		do
		{
			now=0;
			for(i=0;i<x;i++) now+=cnt[id[i]][1];
			for(i=x;i<3;i++) now+=cnt[id[i]][0];
			ans=min(ans,now);
		}
		while(next_permutation(id.begin(),id.end()));
		printf("%d\n",ans/2);
	}
	return 0;
}
/*
1
5
11000
11000
10000
*/
