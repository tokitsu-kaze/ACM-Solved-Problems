#include<bits/stdc++.h>
using namespace std;
struct node{double l,r;}a[1005];
int main()
{
	int n,d,x,y,i,ok,ans;
	double r;
	scanf("%d%d",&n,&d);
	ok=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if(y>d) ok=0;
		a[i]={x-sqrt(d*d-y*y),x+sqrt(d*d-y*y)};
	}
	if(!ok) return 0*puts("-1");
	sort(a+1,a+1+n,[](node x,node y){
		return x.r<y.r;
	});
	r=a[1].r;
	ans=1;
	for(i=2;i<=n;i++)
	{
		if(a[i].l>r)
		{
			ans++;
			r=a[i].r;
		}
	}
	printf("%d\n",ans);
	return 0;
}
