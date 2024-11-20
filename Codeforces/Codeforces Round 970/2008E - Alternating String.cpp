#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int t,n,i,j,k,ans,pre[2][26],suf[2][26];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		memset(suf,0,sizeof suf);
		for(i=1;i<=n;i++) suf[i&1][s[i]-'a']++;
		memset(pre,0,sizeof pre);
		ans=INF;
		if(n%2==0)
		{
			for(i=0;i<26;i++)
			{
				for(j=0;j<26;j++)
				{
					ans=min(ans,n-(suf[0][i]+suf[1][j]));
				}
			}
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				suf[i&1][s[i]-'a']--;
				for(j=0;j<26;j++)
				{
					for(k=0;k<26;k++)
					{
						ans=min(ans,n-(pre[1][j]+pre[0][k]
									  +suf[0][j]+suf[1][k]));
					}
				}
				pre[i&1][s[i]-'a']++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
5
abcab
*/
