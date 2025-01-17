#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int T,n,m,q,p,ans,i,x,y,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		vector<int> res;
		x=0;
		y=n+1;
		l=r=m;
		if(m==1) x=1;
		else if(m==n) y=n;
		for(i=1;i<=q;i++)
		{
			scanf("%d",&p);
			if(p<=x)
			{
				y--;
				l--;
			}
			else if(p>=y)
			{
				x++;
				r++;
			}
			else if(p<l)
			{
				l--;
				if(x>=1) x++;
				if(y<=n) y--;
			}
			else if(p>r)
			{
				r++;
				if(x>=1) x++;
				if(y<=n) y--;
			}
			else
			{
				if(x>=0 && p!=1) x++;
				if(y<=n+1 && p!=n) y--;
			}
			if(i==1 && p==m)
			{
				l=INF;
				r=-INF;
			}
			x=min(x,n);
			y=max(y,1);
			r=min(r,n);
			l=max(l,1);
			if(x>=l)
			{
				l=1;
				x=-INF;
			}
			if(y<=r)
			{
				r=n;
				y=INF;
			}
			if(x>=y)
			{
				x=n;
				y=INF;
			}
//			printf("%d %d %d %d\n",x,y,l,r);
			ans=max(0,r-l+1)+max(0,x)+max(0,n-y+1);
			res.push_back(ans);
		}
		for(i=0;i<q;i++) printf("%d%c",res[i]," \n"[i+1==q]);
	}
	return 0;
}
/*
2
18 2 5
9 3 14 1 1
20 19 5
1 18 5 19 20
*/
