#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],res[MAX],vis[MAX];
int main()
{
	int T,n,k,i,pos0,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<=n;i++) vis[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			vis[a[i]]=1;
		}
		for(i=0;i<=n;i++)
		{
			if(!vis[i])
			{
				x=i;
				break;
			}
		}
		a[n]=x;
		k%=(n+1);
		for(i=0;i<n;i++) res[i]=a[(i-k+n+1)%(n+1)];
		for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i+1==n]);
	}
	return 0;
}
/*
0 1 3 2
2 0 1 3
3 2 0 1
1 3 2 0
0 1 3
找找规律，
发现每次是往数组开头插入当前数组mex，
然后删除数组最后一个数;
再发现其实就是原数组后再接一个mex，
n+1个数在循环移动
*/
