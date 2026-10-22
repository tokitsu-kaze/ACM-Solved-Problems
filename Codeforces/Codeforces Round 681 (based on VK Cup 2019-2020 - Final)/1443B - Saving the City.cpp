#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int dp[MAX];
char s[MAX];
int main()
{
	int T,n,i,a,b,lst;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		scanf("%s",s+1);
		n=strlen(s+1);
		lst=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				dp[i]=a;
				lst=i;
				break;
			}
			else dp[i]=0;
		}
		for(i=lst+1;i<=n;i++)
		{
			if(s[i]=='1') 
			{
				dp[i]=dp[lst]+min(a,(i-lst-1)*b);
				lst=i;
			}
			else dp[i]=dp[i-1];
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
