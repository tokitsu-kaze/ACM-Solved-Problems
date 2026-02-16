#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
char s[MAX],t[MAX];
int main()
{
	int T,n,m,i,j,cnt[26],ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=m;i++) cnt[t[i]-'a']++;
		for(i=1;i<=n;i++) cnt[s[i]-'a']--;
		ok=1;
		for(i=0;i<26;i++)
		{
			if(cnt[i]<0) ok=0;
		}
		if(!ok)
		{
			puts("Impossible");
			continue;
		}
		string res;
		j=1;
		for(i=0;i<26;i++)
		{
			while(j<=n && s[j]-'a'<=i) res+=s[j++];
			while(cnt[i]--) res+=('a'+i);
		}
		puts(res.c_str());
	}
	return 0;
}
