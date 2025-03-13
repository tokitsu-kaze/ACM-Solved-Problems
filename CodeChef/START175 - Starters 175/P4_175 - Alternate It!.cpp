#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,cnt[2],ok,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		ok=1;
		for(i=2;i<=n;i++)
		{
			if(s[i]==s[i-1]) ok=0;
		}
		if(ok)
		{
			puts("0");
			continue;
		}
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++) cnt[s[i]-'0']++;
		if(abs(cnt[0]-cnt[1])<=1)
		{
			puts("1");
			continue;
		}
		if(abs(cnt[0]-cnt[1])<=3)
		{
			puts("2");
			continue;
		}
		puts("3");
	}
	return 0;
}
/*
3
101011
1010110101
1101011
*/
