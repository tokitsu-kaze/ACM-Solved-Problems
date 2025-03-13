#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int MAX=2e5+10;
char s[55][55];
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i<=(n+1-i))
		{
			for(j=i;j<=(n+1-i);j++)
			{
				for(k=i;k<=(n+1-i);k++)
				{
					if(i&1) s[j][k]='#';
					else s[j][k]='.';
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		s[i][n+1]='\0';
		puts(s[i]+1);
	}
	return 0;
}
