#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
int a[MAX],n;
int ck(int x)
{
	int i,j;
	for(i=1,j=n-x+1;i<=x;i++,j++)
	{
		if(a[i]*2>a[j]) return 0;
	}
	return 1;
}
int main()
{
	int l,r,mid,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	l=0;
	r=n/2;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}

