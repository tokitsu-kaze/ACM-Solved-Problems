#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int x,y;}a[MAX],b[MAX];
ll mx[MAX];
int main()
{
	int T,n,m,i,j;
	ll ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		for(i=1;i<=m;i++) scanf("%d%d",&b[i].x,&b[i].y);
		sort(a+1,a+1+n,[](node a,node b){
			return a.y>b.y;
		});
		priority_queue<int,vector<int>,greater<int>> q;
		ans=now=0;
		for(i=n+1,j=1;i;i--)
		{
			while(j<=n && a[j].y>=i-1)
			{
				now+=a[j].x;
				q.push(a[j].x);
				j++;
			}
			while(q.size()>i)
			{
				now-=q.top();
				q.pop();
			}
			if(q.size()==i) mx[i]=now-q.top();
			else mx[i]=now;
			ans=max(ans,now);
		}
		for(i=2;i<=n+1;i++) mx[i]=max(mx[i],mx[i-1]);
		for(i=1;i<=m;i++) printf("%lld%c",max(ans,b[i].x+mx[b[i].y+1])," \n"[i==m]);
	}
	return 0;
}
/*
考虑枚举买i个，在y>=i-1中选最大的i个。
从大到小倒着枚举，在y>=i-1中，x较小的一旦被踢出去就不会再选了。
预处理出最多买i个的最大值mx[i]。
查询不选的话就是ans，选的话就是x+mx[y+1]。
*/
