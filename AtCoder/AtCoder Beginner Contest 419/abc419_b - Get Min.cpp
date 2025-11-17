#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2000+10;
int main()
{
	int m,op,x;
	priority_queue<int,vector<int>,greater<int>> q;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			q.push(x);
		}
		else
		{
			printf("%d\n",q.top());
			q.pop();
		}
	}
	return 0;
}
