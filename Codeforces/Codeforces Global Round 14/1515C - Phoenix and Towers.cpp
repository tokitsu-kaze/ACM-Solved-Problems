#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int v,id;}a[MAX];
int col[MAX];
int main()
{
	int T,n,m,x,i,j,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&x);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i].v);
			a[i].id=i;
		}
		sort(a+1,a+1+n,[](node x,node y){
			return x.v<y.v;
		});
		priority_queue<pair<int,int>> q;
		for(i=1;i<=m;i++) q.push({0,i});
		for(i=1;i<=n;i++)
		{
			auto it=q.top();
			q.pop();
			col[a[i].id]=it.second;
			it.first=-(-it.first+a[i].v);
			q.push(it);
		}
		puts("YES");
		for(i=1;i<=n;i++) printf("%d%c",col[i]," \n"[i==n]);
	}
	return 0;
}

