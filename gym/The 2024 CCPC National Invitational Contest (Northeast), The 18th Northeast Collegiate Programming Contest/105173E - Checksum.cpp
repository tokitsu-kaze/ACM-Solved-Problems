#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX],ans[MAX];
int main()
{
	int T,n,k,i,j,cnt,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		cnt=0;
		for(i=1;i<=n;i++) cnt+=s[i]-'0';
		ok=0;
		for(i=0;i<min(1<<k,4*n);i++)
		{
			if(i==cnt+__builtin_popcount(i))
			{
				for(j=0;j<k;j++) ans[j]='0'+((i>>j)&1);
				reverse(ans,ans+k);
				ans[k]='\0';
				puts(ans);
				ok=1;
				break;
			}
		}
		if(!ok) puts("None");
	}
	return 0;
}
