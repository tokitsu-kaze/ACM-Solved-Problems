#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,now;
	char s[105],res[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		now=s[1]-'0';
		for(i=2;i<=n;i++)
		{
			if(s[i]=='0') res[i]='+';
			else
			{
				if(now)
				{
					res[i]='-';
					now--;
				}
				else
				{
					res[i]='+';
					now++;
				}
			}
		}
		res[n+1]='\0';
		puts(res+2);
	}
	return 0;
}
