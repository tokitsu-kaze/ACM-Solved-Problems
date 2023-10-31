#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int n,m,i,ans,g,tmp;
	scanf("%d%d",&n,&m);
	set<int> s;
	for(i=1;i<=n;i++) s.insert(i);
	s.insert(0);
	ans=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&g);
		tmp=*(--s.upper_bound(g));
		if(tmp>0)
		{
			ans++;
			s.erase(tmp);
		}
		else break;
	}
	printf("%d\n",ans);
	return 0;
}
