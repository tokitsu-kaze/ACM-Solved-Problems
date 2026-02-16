#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
char s[MAX],ans[MAX];
int main()
{
	int T,n,k,i,j,cnt[2],f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++) cnt[s[i]-'0']++;
		for(i=1;i<=k;i++)
		{
			if(cnt[0]>cnt[1]) f=0;
			else f=1;
			for(j=i;j<=n;j+=k)
			{
				ans[j]='0'+f;
				cnt[f]--;
				f^=1;
			}
		}
		if(cnt[0]==0 && cnt[1]==0) puts("Yes");
		else puts("No");
	}
	return 0;
}
