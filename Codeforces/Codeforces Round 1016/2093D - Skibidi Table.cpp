#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll get_xy(int x1,int y1,int x2,int y2,ll l,ll r,int x,int y)
{
//	printf("%d %d %d %d %lld %lld\n",x1,y1,x2,y2,l,r);
	if(l==r) return l;
	ll len=(r-l+1)/4;
	int midx=(x1+x2)>>1;
	int midy=(y1+y2)>>1;
	if(x<=midx && y<=midy) return get_xy(x1,y1,midx,midy,l,l+len-1,x,y);
	else if(x>midx && y>midy) return get_xy(midx+1,midy+1,x2,y2,l+len,l+2*len-1,x,y);
	else if(x>midx && y<=midy) return get_xy(midx+1,y1,x2,midy,l+2*len,l+3*len-1,x,y);
	else return get_xy(x1,midy+1,midx,y2,l+3*len,r,x,y);
}
pair<int,int> get_d(int x1,int y1,int x2,int y2,ll l,ll r,ll d)
{
//	printf("%d %d %d %d %lld %lld\n",x1,y1,x2,y2,l,r);
	if(x1==x2 && y1==y2) return {x1,y1};
	ll len=(r-l+1)/4;
	int midx=(x1+x2)>>1;
	int midy=(y1+y2)>>1;
	if(d<=l+len-1) return get_d(x1,y1,midx,midy,l,l+len-1,d);
	else if(d<=l+2*len-1) return get_d(midx+1,midy+1,x2,y2,l+len,l+2*len-1,d);
	else if(d<=l+3*len-1) return get_d(midx+1,y1,x2,midy,l+2*len,l+3*len-1,d);
	else return get_d(x1,midy+1,midx,y2,l+3*len,r,d);
}
int main()
{
	int T,n,q,x,y;
	ll d;
	char op[5];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		while(q--)
		{
			scanf("%s",op);
			if(op[0]=='-')
			{
				scanf("%d%d",&x,&y);
				x--;
				y--;
				printf("%lld\n",get_xy(0,0,(1<<n)-1,(1<<n)-1,1,1LL<<(2*n),x,y));
			}
			else
			{
				scanf("%lld",&d);
				auto it=get_d(0,0,(1<<n)-1,(1<<n)-1,1,1LL<<(2*n),d);
				printf("%d %d\n",it.first+1,it.second+1);
			}
		}
	}
	return 0;
}

