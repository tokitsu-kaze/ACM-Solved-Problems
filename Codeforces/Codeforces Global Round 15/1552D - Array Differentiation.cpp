#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int n,a[12],ok;
void dfs(int x,int sum,int cnt)
{
	if(x==n+1)
	{
		if(sum==0 && cnt>0) ok=1;
		return;
	}
	dfs(x+1,sum,cnt);
	dfs(x+1,sum+a[x],cnt+1);
	dfs(x+1,sum-a[x],cnt+1);
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ok=0;
		dfs(1,0,0);
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
相当于给你n个点，告诉你n条边的边权，问你是否有给点权赋值的方案。
如果是构造2n个点，那么随便做可以做到互不影响。
考虑最好互不影响的情况：是一棵树！
那么一棵树就只有n-1条边，但多一条边就变成了基环树。
所以至少会存在一个环。为了没有冲突，他们的边权和得是0。
然后看样例1，环是1-5-2-3-1，边权是4，5，10，-1，猜测边权可以选择是否取反。
所以直接O(T*3^n)爆搜即可。
*/
