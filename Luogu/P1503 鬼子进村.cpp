#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int st[MAX],top;
int main()
{
	int n,m,i,x;
	char op[2];
	scanf("%d%d",&n,&m);
	set<int> s;
	s.insert(0);
	s.insert(n+1);
	top=0;
	while(m--)
	{
		scanf("%s",op);
		if(op[0]=='D')
		{
			scanf("%d",&x);
			s.insert(x);
			st[top++]=x;
		}
		else if(op[0]=='R') s.erase(st[--top]);
		else
		{
			scanf("%d",&x);
			auto it=s.lower_bound(x);
			if(*it==x) puts("0");
			else printf("%d\n",*it-*(--it)-1);
		}
	}
	return 0;
}
