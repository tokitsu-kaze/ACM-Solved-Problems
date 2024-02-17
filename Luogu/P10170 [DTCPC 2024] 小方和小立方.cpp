#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e4+10;
char s[MAX];
int main()
{
	int n,i,j,ans,cnt[33];
	scanf("%s",s+1);
	n=strlen(s+1);
	ans=0;
	for(i=1;i<=n;i++)
	{
		string now,tmp;
		memset(cnt,0,sizeof cnt);
		for(j=0;i+j<=n;j++)
		{
			now+=s[i+j];
			cnt[s[i+j]-'a']++;
			if(cnt[s[i+j]-'a']>2) break;
			tmp=now;
			reverse(tmp.begin(),tmp.end());
			if(now==tmp) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}


