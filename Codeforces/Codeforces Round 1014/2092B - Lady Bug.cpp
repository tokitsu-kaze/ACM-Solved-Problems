#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char a[MAX],b[MAX];
int main()
{
	int T,n,i,cnt[2],now[2];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		memset(cnt,0,sizeof cnt);
		memset(now,0,sizeof now);
		for(i=1;i<=n;i++)
		{
			if(a[i]=='1')
			{
				if(cnt[!(i&1)]>0) cnt[!(i&1)]--;
				else now[i&1]++;
			}
			if(b[i]=='0')
			{
				if(now[!(i&1)]>0) now[!(i&1)]--;
				else cnt[i&1]++;
			}
		}
		if(now[0]==0 && now[1]==0) puts("YES");
		else puts("NO");
	}
	return 0;
}
