#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int tag[MAX];
set<int> s[MAX];
int main()
{
	int n,m,q,i,op,x,y;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
	{
		tag[i]=0;
		s[i].clear();
	}
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			scanf("%d",&y);
			s[x].insert(y);
		}
		else if(op==2) tag[x]=1;
		else
		{
			scanf("%d",&y);
			if(tag[x]||s[x].count(y)) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
