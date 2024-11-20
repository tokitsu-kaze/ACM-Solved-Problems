#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int t,n,i,j,k,sq,ok;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		sq=sqrt(n+0.5);
		while(sq*sq<n) sq++;
		while(sq*sq>n) sq--;
		if(sq*sq!=n)
		{
			puts("No");
			continue;
		}
		ok=1;
		k=1;
		for(i=1;i<=sq;i++)
		{
			for(j=1;j<=sq;j++)
			{
				if(i==1||i==sq||j==1||j==sq)
				{
					if(s[k]!='1') ok=0;
				}
				else
				{
					if(s[k]!='0') ok=0;
				}
				k++;
			}
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
