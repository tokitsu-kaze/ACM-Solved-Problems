#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
char s[MAX];
int main()
{
	int T,n,i,j,cnt[11],sum,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		memset(cnt,0,sizeof cnt);
		n=strlen(s+1);
		sum=0;
		for(i=1;i<=n;i++)
		{
			sum+=s[i]-'0';
			cnt[s[i]-'0']++;
		}
		ok=0;
		for(i=0;i<=min(9,cnt[2]);i++)
		{
			for(j=0;j<=min(9,cnt[3]);j++)
			{
				if((sum-i*2-j*3+i*4+j*9)%9==0) ok=1;
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
