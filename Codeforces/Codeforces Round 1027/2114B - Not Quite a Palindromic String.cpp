#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,k,i,cnt[2],tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++) cnt[s[i]-'0']++;
		tmp=(n-2*k)/2;
		cnt[0]-=tmp;
		cnt[1]-=tmp;
		if(cnt[0]<0||cnt[1]<0) puts("NO");
		else if((cnt[0]&1) || (cnt[1]&1)) puts("NO");
		else puts("YES");
	}
	return 0;
}
