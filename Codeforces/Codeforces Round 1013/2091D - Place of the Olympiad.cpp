#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int ck(int x,int cnt,int m)
{
	int a,b;
	ll res;
	a=cnt/x;
	b=cnt%x;
	res=1LL*(x+1)*(a-1)+x;
	if(b) res+=b+1;
	return res<=m;
}
int main()
{
	int T,n,m,k,tmp,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		tmp=(k+n-1)/n;
		l=1;
		r=m;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid,tmp,m)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
