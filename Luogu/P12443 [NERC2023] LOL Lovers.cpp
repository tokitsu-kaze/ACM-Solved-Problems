#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,cnt[256],cnt2[256],ans;
	char s[205];
	while(~scanf("%d",&n))
	{
		scanf("%s",s+1);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++) cnt[s[i]]++;
		memset(cnt2,0,sizeof cnt2);
		ans=-1;
		for(i=1;i<n;i++)
		{
			cnt[s[i]]--;
			cnt2[s[i]]++;
			if(cnt['L']!=cnt2['L']&&cnt['O']!=cnt2['O'])
			{
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
