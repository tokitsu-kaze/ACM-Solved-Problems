#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
int a[MAX],cnt[MAX];
int main()
{
	int n,k,i,j,l,r,now;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;i++) cnt[i]=0;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	now=0;
	l=1;
	r=n;
	for(i=1,j=0;i<=n;i++)
	{
		while(j+1<=n&&now<k)
		{
			j++;
			cnt[a[j]]++;
			if(cnt[a[j]]==1) now++;
		}
		if(now==k)
		{
			if(j-i+1<r-l+1)
			{
				l=i;
				r=j;
			}
		}
		cnt[a[i]]--;
		if(cnt[a[i]]==0) now--;
	}
	printf("%d %d\n",l,r);
	return 0;
}
