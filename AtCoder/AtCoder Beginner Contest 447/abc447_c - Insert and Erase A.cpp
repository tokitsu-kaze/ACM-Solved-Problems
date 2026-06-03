#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
char s[MAX],t[MAX];
int main()
{
	int n,m,i,j,ans;
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	ans=0;
	i=j=1;
	while(i<=n && j<=m)
	{
		if(s[i]==t[j])
		{
			i++;
			j++;
			continue;
		}
		if(s[i]=='A')
		{
			ans++;
			i++;
		}
		else if(t[j]=='A')
		{
			ans++;
			j++;
		}
		else
		{
			ans=-1;
			break;
		}
	}
	if(i<=n)
	{
		while(i<=n)
		{
			if(s[i]=='A')
			{
				ans++;
				i++;
			}
			else
			{
				ans=-1;
				break;
			}
		}
	}
	else if(j<=m)
	{
		while(j<=m)
		{
			if(t[j]=='A')
			{
				ans++;
				j++;
			}
			else
			{
				ans=-1;
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
