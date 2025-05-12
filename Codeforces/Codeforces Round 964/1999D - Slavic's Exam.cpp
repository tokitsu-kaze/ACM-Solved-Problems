#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX],t[MAX];
int main()
{
	int T,n,m,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		for(i=1,j=0;i<=n;i++)
		{
			if(s[i]=='?')
			{
				if(j+1<=m)
				{
					s[i]=t[j+1];
					j++;
				}
				else s[i]='a';
			}
			else
			{
				if(s[i]==t[j+1]) j++;
			}
		}
		if(j==m)
		{
			puts("YES");
			puts(s+1);
		}
		else puts("NO");
	}
	return 0;
}
