#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
char s[MAX];
int main()
{
	int T,n,i,j,cnt[26],id[26],ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++) cnt[s[i]-'a']++;
		ok=1;
		for(i=0;i<26;i++)
		{
			if(cnt[i]>(n+1)/2) ok=0;
		}
		if(!ok)
		{
			puts("No");
			continue;
		}
		for(i=0;i<26;i++) id[i]=i;
		sort(id,id+26,[&](int x,int y){
			return cnt[x]>cnt[y];
		});
		j=0;
		for(i=1;i<=n;i+=2)
		{
			if(cnt[id[j]]==0) j++;
			cnt[id[j]]--;
			s[i]='a'+id[j];
		}
		for(i=2;i<=n;i+=2)
		{
			if(cnt[id[j]]==0) j++;
			cnt[id[j]]--;
			s[i]='a'+id[j];
		}
		s[n+1]='\0';
		puts("Yes");
		puts(s+1);
	}
	return 0;
}
