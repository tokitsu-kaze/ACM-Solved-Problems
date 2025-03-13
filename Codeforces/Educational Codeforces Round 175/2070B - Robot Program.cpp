#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int now[MAX];
int main()
{
	int T,n,x,i,pos;
	ll k,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%lld",&n,&x,&k);
		scanf("%s",s+1);
		now[0]=x;
		for(i=1;i<=n;i++)
		{
			now[i]=now[i-1];
			if(s[i]=='L') now[i]--;
			else now[i]++;
		}
		pos=INF;
		for(i=1;i<=n;i++)
		{
			if(now[i]==0)
			{
				pos=i;
				break;
			}
		}
		if(pos>n || pos>k)
		{
			puts("0");
			continue;
		}
		k-=pos;
		ans=1;
		now[0]=0;
		
		pos=INF;
		for(i=1;i<=n;i++)
		{
			now[i]=now[i-1];
			if(s[i]=='L') now[i]--;
			else now[i]++;
			if(now[i]==0)
			{
				pos=i;
				break;
			}
		}
		if(pos>n || pos>k)
		{
			puts("1");
			continue;
		}
		ans+=k/pos;
		k%=pos;
		printf("%lld\n",ans);
	}
	return 0;
}
