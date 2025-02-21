#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int MAX=2e5+10;
char s[105];
int main()
{
	int n,i,j,k,ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			for(k=j+1;k<=n;k++)
			{
				if(s[i]=='A' && s[j]=='B' && s[k]=='C')
				{
					if(j-i==k-j) ans++;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
