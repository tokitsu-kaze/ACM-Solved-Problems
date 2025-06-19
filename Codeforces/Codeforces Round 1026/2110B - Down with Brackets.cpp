#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int vis[MAX];
int main()
{
	int T,n,i,cnt,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(i=1;i<=n;i++) vis[i]=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='(')
			{
				vis[i]=1;
				break;
			}
		}
		for(i=n;i;i--)
		{
			if(s[i]==')')
			{
				vis[i]=1;
				break;
			}
		}
		ok=1;
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			if(s[i]=='(') cnt++;
			else cnt--;
			if(cnt<0) ok=0;
		}
		if(ok) puts("NO");
		else puts("YES");
	}
	return 0;
}

