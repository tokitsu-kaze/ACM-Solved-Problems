#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX];
set<int> pos[26];
int main()
{
	int n,i,q,op,l,r,x,ans;
	char c[2];
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=0;i<26;i++)
	{
		pos[i].clear();
		pos[i].insert(INF);
	}
	for(i=1;i<=n;i++) pos[s[i]-'a'].insert(i);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%s",&x,c);
			if(s[x]==c[0]) continue;
			pos[s[x]-'a'].erase(x);
			s[x]=c[0];
			pos[s[x]-'a'].insert(x);
		}
		else
		{
			scanf("%d%d",&l,&r);
			ans=0;
			for(i=0;i<26;i++)
			{
				x=*pos[i].lower_bound(l);
				if(x<=r) ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
