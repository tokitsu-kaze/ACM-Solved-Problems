#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct node{int x,y;}a[MAX];
int st[MAX],top;
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,[](node a,node b){
		if(a.x==b.x) return a.y<b.y;
		return a.x<b.x;
	});
	top=0;
	st[++top]=a[1].y;
	for(i=2;i<=n;i++)
	{
		if(st[top]>a[i].y) st[++top]=a[i].y;
		else
		{
			while(top>1 && a[i].y>=st[top-1])
			{
				st[top-1]=st[top];
				top--;
			}
		}
	}
	printf("%d\n",top);
	return 0;
}
/*
建图转化成求连通块个数。
按 x 排序消降维，每次考虑一个新的 y 是否能与前面的连边。
要注意，可能可以将前面多个连通块连在一起。
*/
