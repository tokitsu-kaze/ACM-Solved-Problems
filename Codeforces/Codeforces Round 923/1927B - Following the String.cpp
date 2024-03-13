#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char s[MAX];
int cnt[26];
int main()
{
	int t,n,i,j,tot,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof cnt);
		tot=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x==0)
			{
				s[i]='a'+tot;
				tot++;
			}
			else
			{
				for(j=0;j<tot;j++)
				{
					if(cnt[j]==x)
					{
						s[i]='a'+j;
						break;
					}
				}
			}
			cnt[s[i]-'a']++;
		}
		s[n+1]='\0';
		puts(s+1);
	}
	return 0;
}
