#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=50000+10;
const int mod=998244353;
int main()
{
	int n,i;
	char s[111],a[2],b[2];
	scanf("%d%s%s",&n,a,b);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]!=a[0]) s[i]=b[0];
	}
	puts(s+1);
	return 0;
}
