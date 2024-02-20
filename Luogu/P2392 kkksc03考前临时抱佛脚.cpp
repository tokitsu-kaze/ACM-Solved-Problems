#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int a[22],res;
void dfs(int pos,int x,int y)
{
	if(pos==-1)
	{
		res=min(res,max(x,y));
		return;
	}
	dfs(pos-1,x+a[pos],y);
	dfs(pos-1,x,y+a[pos]);
}
int main()
{
	int i,j,n[5],ans;
	ans=0;
	for(i=0;i<4;i++) scanf("%d",&n[i]);
	for(i=0;i<4;i++)
	{
		for(j=0;j<n[i];j++) scanf("%d",&a[j]);
		res=INF;
		dfs(n[i]-1,0,0);
		ans+=res;
	}
	printf("%d\n",ans);
	return 0;
}
