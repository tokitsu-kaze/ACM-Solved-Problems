#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
char s[MAX];
int main()
{
	int T,n,i,cnt0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		cnt0=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='0') cnt0++;
		}
		if(cnt0==0) puts("DRAW");
		else if((n&1) && s[(n+1)/2]=='0' && cnt0>1) puts("ALICE");
		else puts("BOB");
	}
	return 0;
}

