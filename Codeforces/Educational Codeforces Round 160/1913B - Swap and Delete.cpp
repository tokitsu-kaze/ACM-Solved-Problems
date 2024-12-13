#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,cnt[2],ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		n=strlen(s);
		memset(cnt,0,sizeof cnt);
		for(i=0;i<n;i++) cnt[s[i]-'0']++;
		ans=0;
		for(i=0;i<n;i++)
		{
			if(cnt[(s[i]-'0')^1]) cnt[(s[i]-'0')^1]--;
			else
			{
				ans=n-i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
