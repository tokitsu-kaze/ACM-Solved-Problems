#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
char col[MAX],s[MAX][3];
int op[MAX],x[MAX];
int main()
{
	int n,q,i;
	scanf("%d%d",&n,&q);
	set<int> now,ban;
	for(i=1;i<=n;i++) now.insert(i);
	for(i=1;i<=q;i++)
	{
		scanf("%d",&op[i]);
		if(op[i]==1)
		{
			scanf("%d",&x[i]);
			if(now.count(x[i]))
			{
				now.erase(x[i]);
				ban.insert(x[i]);
			}
			else if(ban.count(x[i]))
			{
				ban.erase(x[i]);
				now.insert(x[i]);
			}
		}
		else scanf("%s",s[i]);
	}
	for(i=1;i<=n;i++) col[i]='a';
	for(i=q;i;i--)
	{
		if(op[i]==2)
		{
			for(auto &it:now) col[it]=s[i][0];
			now.clear();
		}
		else
		{
			if(now.count(x[i]))
			{
				now.erase(x[i]);
				ban.insert(x[i]);
			}
			else if(ban.count(x[i]))
			{
				ban.erase(x[i]);
				now.insert(x[i]);
			}
		}
	}
	col[n+1]='\0';
	puts(col+1);
	return 0;
}
