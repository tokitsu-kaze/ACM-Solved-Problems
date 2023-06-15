#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
int main()
{
	int n,op,x;
	scanf("%d",&n);
	priority_queue<int,vector<int>,greater<int>> q;
	while(n--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			q.push(x);
		}
		else if(op==2) printf("%d\n",q.top());
		else q.pop();
	}
	return 0;
}
