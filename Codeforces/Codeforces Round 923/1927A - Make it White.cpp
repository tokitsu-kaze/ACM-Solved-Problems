#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
int main()
{
	int t,n,i,l,r;
	char s[12];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		l=r=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='B')
			{
				l=i;
				break;
			}
		}
		for(i=n;i;i--)
		{
			if(s[i]=='B')
			{
				r=i;
				break;
			}
		}
		printf("%d\n",r-l+1);
	}
	return 0;
}
