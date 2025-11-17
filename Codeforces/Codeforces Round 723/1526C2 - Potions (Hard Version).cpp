#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,x;
	ll now;
	scanf("%d",&n);
	priority_queue<int> q;
	now=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		q.push(-x);
		now+=x;
		if(now<0)
		{
			now+=q.top();
			q.pop();
		}
	}
	printf("%d\n",(int)q.size());
	return 0;
}

