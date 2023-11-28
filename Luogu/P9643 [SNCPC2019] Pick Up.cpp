#include <bits/stdc++.h>
using namespace std;
typedef double db;
db cal_time(db a,db b,db c,db d,db v)
{
	return (abs(c-a)+abs(d-b))/v;
}
int main()
{
	int t;
	db va,vb,xa,ya,xb,yb,xc,yc,xd,yd,ans,ta,tb,mt,dis;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf",&va,&vb);
		scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc);
		xd=max(min(xa,xb),min(max(xa,xb),xc));
		yd=max(min(ya,yb),min(max(ya,yb),yc));
		ans=cal_time(xa,ya,xc,yc,va);
		ta=cal_time(xa,ya,xd,yd,va);
		tb=cal_time(xb,yb,xd,yd,vb);
		if(ta<tb) ans=min(ans,cal_time(xb,yb,xc,yc,vb));
		else
		{
			mt=cal_time(xa,ya,xb,yb,va+vb);
			dis=abs(xc-xa)+abs(yc-ya)-va*mt;
			ans=min(ans,mt+dis/vb);
		}
		printf("%.10f\n",ans);
	}
	return 0;
}
