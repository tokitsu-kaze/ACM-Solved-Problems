#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int qst,op,x;
	scanf("%d",&qst);
	queue<int> q;
	while(qst--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			q.push(x);
		}
		else
		{
			printf("%d\n",q.front());
			q.pop();
		}
	}
	return 0;
}
