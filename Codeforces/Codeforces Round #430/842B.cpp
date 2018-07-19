#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int x,y,r;
	void input()
	{
		scanf("%d%d%d",&x,&y,&r);
	}
}a[MAX];
double dis(int x,int y)
{
	return sqrt(x*x+y*y);
}
int main()
{
	int R,r,n,i,ans;
	while(~scanf("%d%d",&R,&r))
	{
		scanf("%d",&n);
		ans=0;
		r=R-r;
		for(i=0;i<n;i++)
		{
			a[i].input();
			double d=dis(a[i].x,a[i].y);
			if(d-a[i].r-r>=0&&R-d-a[i].r>=0) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}