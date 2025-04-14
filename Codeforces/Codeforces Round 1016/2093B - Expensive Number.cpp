#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int main()
{
	int T,n,i,j,ans;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=0;
		for(i=n;i;i--)
		{
			if(s[i]=='0') ans++;
			else
			{
				for(j=i-1;j;j--)
				{
					if(s[j]!='0') ans++;
				}
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
