#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e4+10;
int ask(int x)
{
	printf("%d\n",x);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
int main()
{
	int l,r,mid,x;
	l=1;
	r=1e9;
	while(l<r)
	{
		mid=(l+r)>>1;
		x=ask(mid+1);
		if(x==-1) l=mid+1;
		else if(x==0) break;
		else r=mid;
	}
	ask(l);
	return 0;
}
