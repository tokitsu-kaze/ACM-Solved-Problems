#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T;
	ll px,py,qx,qy,rx,ry,sx,sy;
	__int128_t t1,t2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&px,&py,&qx,&qy);
		scanf("%lld%lld%lld%lld",&rx,&ry,&sx,&sy);
		if((qx-px)*(sy-ry)!=(sx-rx)*(qy-py)) puts("Yes");
		else
		{
			t1=(qx*qx-px*px)+(qy*qy-py*py);
			t2=(sx*sx-rx*rx)+(sy*sy-ry*ry);
			if(t1*(sx-rx)==t2*(qx-px) &&
			   t1*(sy-ry)==t2*(qy-py)) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
