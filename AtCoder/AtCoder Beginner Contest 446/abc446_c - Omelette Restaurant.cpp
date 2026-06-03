#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int T,n,d,i,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&d);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		queue<int> q;
		for(i=1;i<=n;i++)
		{
			while(a[i]--) q.push(i);
			while(b[i]--) q.pop();
			while(!q.empty())
			{
				x=q.front();
				if(x>i-d) break;
				q.pop();
			}
		}
		printf("%d\n",(int)q.size());
	}
	return 0;
}
