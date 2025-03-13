#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],sum[MAX],cnt[MAX][31][2][2];
int main()
{
	int T,n,q,i,j,pos,x,y,l,r,cnt01,cnt10,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		sum[0]=0;
		memset(cnt[0],0,sizeof cnt[0]);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]^a[i];
			pos=-1;
			for(j=30;~j;j--)
			{
				x=(sum[i-1]>>j)&1;
				y=(sum[i]>>j)&1;
				if(x!=y && pos==-1) pos=j;
				cnt[i][j][0][1]=cnt[i-1][j][0][1];
				cnt[i][j][1][0]=cnt[i-1][j][1][0];
			}
			if(pos!=-1)
			{
				x=(sum[i-1]>>pos)&1;
				y=(sum[i]>>pos)&1;
				cnt[i][pos][x][y]++;
			}
		}
		string ans="";
		while(q--)
		{
			scanf("%d%d",&l,&r);
			ok=1;
			for(j=0;j<=30;j++)
			{
				cnt01=cnt[r][j][0][1]-cnt[l][j][0][1];
				cnt10=cnt[r][j][1][0]-cnt[l][j][1][0];
				if(cnt01>0 && cnt10>0) ok=0;
				if(cnt01>0 && (sum[l-1]>>j)&1) ok=0;
				if(cnt10>0 && !((sum[l-1]>>j)&1)) ok=0;
			}
			if(ok) ans+="1";
			else ans+="0";
		}
		puts(ans.c_str());
	}
	return 0;
}
