#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Cartesian_Tree
{
	int ls[MAX],rs[MAX],vis[MAX],st[MAX],top;
	int build_tree(int n,int *a)
	{
		int i,k;
		top=0;
		for(i=1;i<=n;i++) ls[i]=rs[i]=vis[i]=0;
		for(i=1;i<=n;i++)
		{
			k=top;
			while(k>0&&a[st[k-1]]>a[i]) k--;
			if(k) rs[st[k-1]]=i;
			if(k<top) ls[i]=st[k];
			st[k++]=i;
			top=k;
		}
		for(i=1;i<=n;i++) vis[ls[i]]=vis[rs[i]]=1;
		for(i=1;i<=n;i++)
		{
			if(!vis[i]) return i;
		}
		return -1;
	}
}ct;
int a[MAX],p[MAX],ans[MAX];
void dfs(int x,int cnt,int pre)
{
	if(ct.ls[x]) dfs(ct.ls[x],cnt,1);
	else ans[x-1]=cnt;
	if(ct.rs[x]) dfs(ct.rs[x],cnt+pre,0);
	else ans[x]=cnt+pre;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p[a[i]]=i;
	}
	assert(ct.build_tree(n,p)==a[1]);
	dfs(a[1],0,0);
	for(i=0;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
/*
发现建出来的树是bst，直接在树上dfs一遍就可以得到答案。
但直接模拟插入bst建树会退化。
笛卡尔树有堆和bst性质。
最值分治时：求最值满足堆的性质，左右递归下去满足bst性质。
按插入顺序建bst时：插入顺序满足堆的性质，值满足bst的性质。
所以可以通过建笛卡尔树来按插入顺序建bst。
*/
