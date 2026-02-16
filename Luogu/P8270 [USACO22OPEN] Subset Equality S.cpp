#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX],t[MAX],now[MAX],ans[MAX];
int ban[26][26];
int main()
{
	int n,m,k,x,y,i,j,q,ok,cas;
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	memset(ban,0,sizeof ban);
	for(x=0;x<26;x++)
	{
		for(y=x;y<26;y++)
		{
			i=j=1;
			while(i<=n && j<=m)
			{
				while(i<=n && s[i]!=x+'a' && s[i]!=y+'a') i++;
				while(j<=m && t[j]!=x+'a' && t[j]!=y+'a') j++;
				if(i<=n && j<=m)
				{
					if(s[i]!=t[j])
					{
						ban[x][y]=ban[y][x]=1;
						break;
					}
					i++;
					j++;
				}
			}
			while(i<=n && s[i]!=x+'a' && s[i]!=y+'a') i++;
			while(j<=m && t[j]!=x+'a' && t[j]!=y+'a') j++;
			if(i<=n || j<=m) ban[x][y]=ban[y][x]=1;
		}
	}
	scanf("%d",&q);
	for(cas=1;cas<=q;cas++)
	{
		scanf("%s",now+1);
		k=strlen(now+1);
		ok=1;
		for(i=1;i<=k;i++)
		{
			for(j=i;j<=k;j++)
			{
				if(ban[now[i]-'a'][now[j]-'a']) ok=0;
			}
		}
		if(ok) ans[cas]='Y';
		else ans[cas]='N';
	}
	ans[q+1]='\0';
	puts(ans+1);
	return 0;
}
/*
a
aa
1
a
*/
