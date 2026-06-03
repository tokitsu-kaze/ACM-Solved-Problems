#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
char mp[12][12];
int main()
{
	int H,W,h1,h2,w1,w2,ans,i,j,ok;
	scanf("%d%d",&H,&W);
	for(i=1;i<=H;i++) scanf("%s",mp[i]+1);
	ans=0;
	for(h1=1;h1<=H;h1++)
	{
		for(h2=h1;h2<=H;h2++)
		{
			for(w1=1;w1<=W;w1++)
			{
				for(w2=w1;w2<=W;w2++)
				{
					ok=1;
					for(i=h1;i<=h2;i++)
					{
						for(j=w1;j<=w2;j++)
						{
							if(mp[i][j]!=mp[h1+h2-i][w1+w2-j]) ok=0;
						}
					}
					ans+=ok;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
