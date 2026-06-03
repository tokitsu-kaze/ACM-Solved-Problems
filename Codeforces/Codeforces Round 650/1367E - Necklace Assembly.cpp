#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
char s[MAX];
int main()
{
	int T,n,k,i,j,cnt[26],len,nd,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++) cnt[s[i]-'a']++;
		for(i=n;i;i--)
		{
			len=__gcd(i,k);
			nd=i/len;
			now=0;
			for(j=0;j<26;j++) now+=cnt[j]/nd;
			if(now>=len)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
/*
枚举答案 i，块长是 gcd(i,k)，块的数量是 i/gcd(i,k)。
算一算每种字母在一个块里能用几个，看看总数是否>=块长。
*/
