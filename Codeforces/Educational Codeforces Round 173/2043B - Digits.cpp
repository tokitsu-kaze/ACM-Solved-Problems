#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
const int mod=1e9+7;
int main()
{
	int T,n,d,i,j,k,now,cnt[11][11],vis[11];
	memset(cnt,-1,sizeof cnt);
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j+=2)
		{
			cnt[i][j]=0;
			memset(vis,-1,sizeof vis);
			now=0;
			vis[0]=0;
			for(k=1;;k++)
			{
				now=(now*10+i)%j;
				if(vis[now]!=-1)
				{
					if(now==0) cnt[i][j]=k;
					break;
				}
				vis[now]=k;
			}
//			printf("%d %d %d\n",i,j,cnt[i][j]);
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&d);
		if(n>=9) n=9;
		now=1;
		for(i=1;i<=n;i++) now*=i;
		vector<int> res;
		for(i=1;i<=9;i+=2)
		{
			if(cnt[d][i])
			{
				if(now%cnt[d][i]==0) res.push_back(i);
			}
		}
		for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==res.size()]);
	}
	return 0;
}
