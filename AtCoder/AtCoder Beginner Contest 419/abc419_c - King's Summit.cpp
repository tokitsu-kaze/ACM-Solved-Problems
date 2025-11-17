#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int x[MAX],y[MAX],n;
int cal(int a,int b)
{
	int i,res;
	res=0;
	for(i=1;i<=n;i++)
	{
		res=max(res,abs(x[i]-a));
		res=max(res,abs(y[i]-b));
	}
	return res;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	printf("%d\n",cal((x[1]+x[n])/2,(y[1]+y[n])/2));
	return 0;
}
