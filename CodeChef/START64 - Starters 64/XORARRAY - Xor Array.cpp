#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],cnt[MAX][31][2][2];
int main()
{
	int T,n,q,i,j,r,pos,x,y,cnt01,cnt10,ok,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(cnt[0],0,sizeof cnt[0]);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			pos=-1;
			for(j=30;~j;j--)
			{
				x=(a[i-1]>>j)&1;
				y=(a[i]>>j)&1;
				if(x!=y && pos==-1) pos=j;
				cnt[i][j][0][1]=cnt[i-1][j][0][1];
				cnt[i][j][1][0]=cnt[i-1][j][1][0];
			}
			if(pos!=-1)
			{
				x=(a[i-1]>>pos)&1;
				y=(a[i]>>pos)&1;
				cnt[i][pos][x][y]++;
			}
		}
		ans=0;
		for(i=1,r=1;i<=n;i++)
		{
			while(r+1<=n)
			{
				ok=1;
				for(j=0;j<=30;j++)
				{
					cnt01=cnt[r+1][j][0][1]-cnt[i][j][0][1];
					cnt10=cnt[r+1][j][1][0]-cnt[i][j][1][0];
					if(cnt01>0 && cnt10>0) ok=0;
				}
				if(ok) r++;
				else break;
			}
			ans=max(ans,r-i+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
