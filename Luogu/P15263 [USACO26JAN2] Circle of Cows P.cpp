#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
int d[MAX],ans[MAX],n,c;
int cal_dis(int x,int y)
{
	if(x>n) x-=n;
	if(y>n) y-=n;
	return min(abs(d[x]-d[y]),c-abs(d[x]-d[y]));
}
int cal_match(int x,int y,int limt)
{
	int i,j,res,val;
	res=1;
	for(i=x+1,j=y+1;i<=y-1;i++)
	{
		while(j<x+n-1)
		{
			val=cal_dis(i,j);
			if(val<limt && cal_dis(i,j+1)>=val) j++;
			else break;
		}
		if(j<=x+n-1 && cal_dis(i,j)>=limt)
		{
			res++;
			j++;
		}
	}
	return res;
}
int main()
{
	int i,j,val,k;
	scanf("%d%d",&n,&c);
	d[0]=0;
	for(i=1;i<=n;i++) scanf("%d",&d[i]);
	for(i=n+1;i<=2*n;i++) d[i]=d[i-n]+c;
	memset(ans,0,sizeof ans);
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			val=min(d[j]-d[i],c-(d[j]-d[i]));
			k=cal_match(i,j,val);
			ans[k]=max(ans[k],val);
		}
	}
	for(i=n/2-1;i;i--) ans[i]=max(ans[i],ans[i+1]);
	for(i=1;i<=n/2;i++) printf("%d%c",ans[i]," \n"[i==n/2]);
	return 0;
}
/*
感觉挺神秘的，有点对脑电波。
大概做法是，枚举一对作为最小距离，然后去匹配剩下的奶牛，求个最大匹配，最后倒着更新答案。
由于枚举一对会把圆切成两半，有个结论是，最优情况下，其他的匹配一定会跟这一对的线相交。
证明就考虑，如果存在不相交的两条线，调整一下使他们相交，答案会更大。
所以变成两半各选一只匹配成一对，变成二分图最大匹配。
并且发现匹配的端点是单调的，所以可以直接贪心。
复杂度是O(n^3)，但匹配跑不满，所以能过。
*/
