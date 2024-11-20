#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double dist(double a,double b,double x,double y)
{
	return sqrt((a-x)*(a-x)+(b-y)*(b-y));
}
int main()
{
	int t,px,py,ax,ay,bx,by;
	double ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d",&px,&py,&ax,&ay,&bx,&by);
		ans=min(max(dist(0,0,ax,ay),dist(px,py,ax,ay)),
				max(dist(0,0,bx,by),dist(px,py,bx,by)));
		ans=min(ans,max({dist(0,0,ax,ay),dist(px,py,bx,by),dist(ax,ay,bx,by)/2}));
		ans=min(ans,max({dist(0,0,bx,by),dist(px,py,ax,ay),dist(ax,ay,bx,by)/2}));
		printf("%.10f\n",ans);
	}
	return 0;
}
