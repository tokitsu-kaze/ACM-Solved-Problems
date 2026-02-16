#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct node{int v,id;}a[MAX][3];
int id[MAX];
int main()
{
	int T,n,i,j,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%d",&a[i][j].v);
				a[i][j].id=j;
			}
			sort(a[i],a[i]+3,[](node x,node y){
				return x.v>y.v;
			});
			id[i]=i;
		}
		sort(id+1,id+1+n,[&](int x,int y){
			return a[x][0].v>a[y][0].v;
		});
		priority_queue<int,vector<int>,greater<int>> q[3];
		ans=0;
		for(i=1;i<=n;i++)
		{
			x=id[i];
			ans+=a[x][0].v;
			q[a[x][0].id].push(a[x][0].v-a[x][1].v);
			if(q[a[x][0].id].size()>n/2)
			{
				ans-=q[a[x][0].id].top();
				q[a[x][0].id].pop();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
