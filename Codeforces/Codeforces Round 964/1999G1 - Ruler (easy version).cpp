#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int ask(int a,int b)
{
	printf("? %d %d\n",a,b);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
int main()
{
	int T,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		l=1;
		r=1000;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ask(1,mid)>mid) r=mid;
			else l=mid+1;
		}
		printf("! %d\n",l);
		fflush(stdout);
	}
	return 0;
}

