#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[105][12];
int main()
{
	int n,i,j,k,ans,cnt[12],mx;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%s",s[i]);
	ans=1e9;
	for(k=0;k<10;k++)
	{
		memset(cnt,0,sizeof cnt);
		for(i=0;i<n;i++)
		{
			for(j=0;j<10;j++)
			{
				if(s[i][j]-'0'==k) cnt[j]++;
			}
		}
		mx=0;
		for(i=0;i<10;i++) mx=max(mx,cnt[i]);
		for(i=9;~i;i--)
		{
			if(cnt[i]==mx)
			{
				ans=min(ans,(mx-1)*10+i);
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
