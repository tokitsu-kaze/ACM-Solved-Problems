#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tar;
int ok,n;
void dfs(ll now,int cnt)
{
	if(cnt<0) return;
	if(now==tar) ok=1;
	if(ok) return;
	for(int i=1;i<=(n+1)/2;i++)
	{
		if((now|(now>>i))==now) continue;
		dfs(now|(now>>i),cnt-1);
	}
}
int main()
{
	int i,ans;
	ll now;
	char s[44];
	scanf("%s",s);
	n=strlen(s);
	if(s[0]=='0') return 0*puts("-1");
	now=0;
	for(i=0;i<n;i++) now=(now<<1)|(s[i]-'0');
	tar=(1LL<<n)-1;
	if(now==tar) return 0*puts("0");
	for(ans=1;ans<n;ans++)
	{
		ok=0;
		dfs(now,ans);
		if(ok)
		{
			printf("%d\n",ans);
			break;
		}
	}
	return 0;
}
