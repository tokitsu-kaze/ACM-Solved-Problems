#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[105];
int main()
{
	int t,n,p,i,mx,now,prean;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&p);
		set<int> s;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s.insert(a[i]);
		}
		mx=(a[n]-1+p)%p;
		while(mx!=a[n] && s.count(mx)) mx=(mx-1+p)%p;
		if(mx==a[n])
		{
			puts("0");
			continue;
		}
		if(a[n]<mx)
		{
			printf("%d\n",mx-a[n]);
			continue;
		}
		prean=a[n];
		now=p-prean;
		for(i=n;i;i--)
		{
			a[i]+=now;
			now=a[i]/p;
			a[i]%=p;
			s.insert(a[i]);
		}
		if(now) s.insert(now);
		mx=prean-1;
		while(s.count(mx)) mx--;
		printf("%d\n",max(0,mx)+p-prean);
	}
	return 0;
}
