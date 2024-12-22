#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int T,n,i,mn,mx,pos,cnt[26];
	char s[12];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++) cnt[s[i]-'a']++;
		mn=INF;
		mx=0;
		for(i=0;i<26;i++)
		{
			if(cnt[i]==0) continue;
			mn=min(mn,cnt[i]);
			mx=max(mx,cnt[i]);
		}
		pos=0;
		for(i=1;i<=n;i++)
		{
			if(cnt[s[i]-'a']==mn) pos=i;
		}
		for(i=1;i<=n;i++)
		{
			if(cnt[s[i]-'a']==mx && s[pos]!=s[i])
			{
				s[pos]=s[i];
				break;
			}
		}
		puts(s+1);
	}
	return 0;
}
