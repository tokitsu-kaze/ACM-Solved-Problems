#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX];
int main()
{
	int T,n,i;
	ll sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		a[0]=0;
		for(i=n;i;i--) a[i]-=a[i-1];
		sum=0;
		for(i=2;i<=n;i++)
		{
			if(a[i]<0) sum+=-a[i];
		}
		if(sum<=a[1]) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
数据范围3e4是何意味，漏打一个0？
转化成差分，对单点操作，然后就简单了。
*/
