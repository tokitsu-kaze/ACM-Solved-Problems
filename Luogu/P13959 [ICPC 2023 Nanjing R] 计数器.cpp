#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct node{int a,b;}op[MAX];
int main()
{
	int T,n,m,i,now,x,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++) scanf("%d%d",&op[i].a,&op[i].b);
		sort(op+1,op+1+m,[](node x,node y){
			return x.a<y.a;
		});
		now=0;
		x=0;
		ok=1;
		for(i=1;i<=m;i++)
		{
			if(op[i].a==now && x!=op[i].b) ok=0;
			if(op[i].b>x+op[i].a-now) ok=0;
			if(op[i].b<x+op[i].a-now &&
			   op[i].b>=op[i].a-now) ok=0;
			now=op[i].a;
			x=op[i].b;
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}

