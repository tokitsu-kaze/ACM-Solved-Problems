#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
char s[MAX],pre;
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		pre='?';
		for(i=1;i<=n;i++)
		{
			if(s[i]=='?') s[i]=pre;
			else pre=s[i];
		}
		pre='?';
		for(i=n;i;i--)
		{
			if(s[i]=='?') s[i]=pre;
			else pre=s[i];
		}
		for(i=1;i<=n;i++)
		{
			if(s[i]=='?') s[i]='1';
		}
		s[n+1]='\0';
		puts(s+1);
	}
	return 0;
}
