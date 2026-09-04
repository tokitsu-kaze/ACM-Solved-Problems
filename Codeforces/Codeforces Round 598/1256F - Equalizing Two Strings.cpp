#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX],t[MAX];
int main()
{
	int T,n,i,j,cnt[26],ok;
	ll ra,rb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++) cnt[s[i]-'a']++;
		ok=1;
		for(i=1;i<=n;i++)
		{
			cnt[t[i]-'a']--;
			if(cnt[t[i]-'a']<0) ok=0;
		}
		if(!ok)
		{
			puts("NO");
			continue;
		}
		ok=0;
		memset(cnt,0,sizeof cnt);
		ra=0;
		for(i=1;i<=n;i++)
		{
			cnt[s[i]-'a']++;
			if(cnt[s[i]-'a']>1) ok=1;
			for(j=s[i]-'a';j<26;j++) ra+=cnt[j];
		}
		memset(cnt,0,sizeof cnt);
		rb=0;
		for(i=1;i<=n;i++)
		{
			cnt[t[i]-'a']++;
			if(cnt[t[i]-'a']>1) ok=1;
			for(j=t[i]-'a';j<26;j++) rb+=cnt[j];
		}
		if(ok || ra%2==rb%2) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
反转任意长度，选择长度为 2，相当于交换相邻两项。
所以看逆序对奇偶就行。
特别的，如果存在相同字母，可以调整奇偶性。
*/
