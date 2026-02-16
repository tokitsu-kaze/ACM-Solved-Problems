#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct node{int w,p;}a[MAX];
int main()
{
	int T,n,i;
	ll now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d%d",&a[i].w,&a[i].p);
		sort(a+1,a+1+n,[](node x,node y){
			if(x.w+x.p==y.w+y.p) return x.p>y.p;
			return x.w+x.p>y.w+y.p;
		});
		priority_queue<int> q;
		now=0;
		for(i=1;i<=n;i++)
		{
			q.push(a[i].w+a[i].p);
			now-=a[i].w;
			if(now<0)
			{
				now+=q.top();
				q.pop();
			}
		}
		printf("%d\n",(int)q.size());
	}
	return 0;
}

