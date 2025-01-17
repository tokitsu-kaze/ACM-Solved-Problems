#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
const int mod=1e9+7;
char s[MAX];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(i=2;i<=n;i++)
		{
			if(s[i]==s[i-1])
			{
				printf("%c%c\n",s[i-1],s[i]);
				goto end;
			}
		}
		for(i=3;i<=n;i++)
		{
			if(s[i]!=s[i-1] && s[i]!=s[i-2] && s[i-1]!=s[i-2])
			{
				printf("%c%c%c\n",s[i-2],s[i-1],s[i]);
				goto end;
			}
		}
		puts("-1");
		end:;
	}
	return 0;
}

