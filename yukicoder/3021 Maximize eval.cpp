#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
char s[MAX];
int main()
{
	int T,n,i,op;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		op=1;
		s[n+1]='-';
		for(i=1;i<=n;i++)
		{
			if(s[i]=='-') op=-1;
			else if(s[i]=='+') op=1;
			else if(s[i]=='?')
			{
				if(op==0)
				{
					if(s[i+1]=='+' || s[i+1]=='-') s[i]='1';
					else
					{
						s[i]='+';
						op=1;
					}
				}
				else if(op==-1)
				{
					s[i]='1';
					op=0;
				}
				else s[i]='9';
			}
			else
			{
				if(op==-1) op=0;
			}
		}
		s[n+1]='\0';
		puts(s+1);
	}
	return 0;
}
