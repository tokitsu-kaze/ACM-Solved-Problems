#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int T,n,i,j,k;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=k;i++) s[i]='(';
			for(i=k+1;i<=2*k;i++) s[i]=')';
			for(i=2*k+1;i<=2*n;i+=2)
			{
				s[i]='(';
				s[i+1]=')';
			}
			s[2*n+1]='\0';
			puts(s+1);
		}
	}
	return 0;
}
