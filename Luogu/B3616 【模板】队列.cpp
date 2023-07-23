#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,op,x;
	scanf("%d",&n);
	queue<int> q;
	while(n--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			q.push(x);
		}
		else if(op==2)
		{
			if(q.empty()) puts("ERR_CANNOT_POP");
			else q.pop();
		}
		else if(op==3)
		{
			if(q.empty()) puts("ERR_CANNOT_QUERY");
			else printf("%d\n",q.front());
		}
		else if(op==4) printf("%d\n",q.size());
		else assert(0);
	}
	return 0;
}
