#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int a[MAX],n,k;
int ck(int x)
{
	int i;
	int cnt=1,pre=a[1];
	for(i=2;i<=n;i++)
	{
		if(a[i]-pre>=x)
		{
			pre=a[i];
			cnt++;
		}
	}
	return cnt>=k;
}
int main()
{
	int i,l,r,mid;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	l=0;
	r=1e9;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	printf("%d\n",l);
}
