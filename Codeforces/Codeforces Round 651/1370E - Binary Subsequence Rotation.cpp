#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
char s[MAX],t[MAX];
int main()
{
	int n,i,cnt[2],now[2],tot;
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	cnt[0]=cnt[1]=now[0]=now[1]=tot=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]==t[i]) continue;
		if(now[(s[i]-'0')^1]) now[(s[i]-'0')^1]--;
		else tot++;
		now[s[i]-'0']++;
		cnt[s[i]-'0']++;
		cnt[t[i]-'0']--;
	}
	if(cnt[0]||cnt[1]) puts("-1");
	else printf("%d\n",tot);
	return 0;
}
