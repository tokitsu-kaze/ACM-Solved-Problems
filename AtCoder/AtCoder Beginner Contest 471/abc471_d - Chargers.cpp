#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int qs,op,t,w,v;
	scanf("%d%d",&qs,&v);
	priority_queue<int> q;
	while(qs--)
	{
		scanf("%d%d",&op,&t);
		if(op==1)
		{
			scanf("%d",&w);
			q.push(w-t);
		}
		else
		{
			if(q.size()==0)
			{
				puts("-1");
				continue;
			}
			w=q.top()+t;
			q.pop();
			printf("%d\n",min(v,w));
		}
	}
	return 0;
}
