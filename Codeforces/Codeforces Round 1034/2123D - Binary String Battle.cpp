#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,k,i,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		cnt=0;
		for(i=1;i<=n;i++) cnt+=s[i]-'0';
		if(cnt<=k || k*2>n) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
