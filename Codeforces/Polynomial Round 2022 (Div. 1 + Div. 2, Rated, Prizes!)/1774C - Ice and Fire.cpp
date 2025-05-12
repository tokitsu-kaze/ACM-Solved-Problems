#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+2);
		now=0;
		for(i=2;i<=n;i++)
		{
			if(i>2 && s[i]==s[i-1]) now++;
			else now=1;
			printf("%d%c",i-now," \n"[i==n]);
		}
	}
	return 0;
}
/*
1
5
0011
*/
