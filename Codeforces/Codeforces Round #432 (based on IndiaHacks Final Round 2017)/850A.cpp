#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=10007;
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
struct Point
{
	int p[6];
	void input()
	{
		for(int i=0;i<5;i++)
		{
			scanf("%d",&p[i]);
		}
	}
}p[1111];
int main()
{
	int n,i,j,k,l,cnt,flag,ans[1111];
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			p[i].input();
		}
		cnt=0;
		for(i=0;i<n;i++)
		{
			flag=0;
			for(j=0;j<n;j++)
			{
				if(j==i) continue;
				for(k=j+1;k<n;k++)
				{
					if(k==i) continue;
					Point a,b;
					double temp1=0,temp2=0,temp3=0;
					for(l=0;l<5;l++)
					{
						a.p[l]=p[j].p[l]-p[i].p[l];
						b.p[l]=p[k].p[l]-p[i].p[l];
						temp1+=a.p[l]*b.p[l];
						temp2+=sqrt(a.p[l]*a.p[l]);
						temp3+=sqrt(b.p[l]*b.p[l]);
					}
					if(sgn(acos(temp1/(temp2*temp3))-PI/2)<0)
					{
						flag=1;
						break;
					}
				}
				if(flag) break;
			}
			if(!flag) ans[cnt++]=i+1;
		}
		printf("%d\n",cnt);
		for(i=0;i<cnt;i++)
		{
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}