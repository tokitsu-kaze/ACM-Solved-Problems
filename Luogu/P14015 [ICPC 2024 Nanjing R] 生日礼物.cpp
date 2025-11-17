#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,cnt[3],ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++)
		{
			if(!(i&1))
			{
				if(s[i]!='2') s[i]^=1;
			}
			cnt[s[i]-'0']++;
		}
		ans=abs(cnt[0]-cnt[1]);
		if(ans>=cnt[2]) ans-=cnt[2];
		else
		{
			ans=cnt[2]-ans;
			ans&=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
