#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
double get_dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int x[MAX],y[MAX];
int main()
{
	int n,i,j;
	double ans;
	scanf("%d",&n);
	ans=1e18;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		for(j=1;j<i;j++) ans=min(ans,get_dis(x[i],y[i],x[j],y[j]));
	}
	printf("%.4f\n",ans);
	return 0;
}
