#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int a[MAX],b[MAX];
int main()
{
	int t,n,k,q,d,p,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k,&q);
		a[0]=b[0]=0;
		for(i=1;i<=k;i++) scanf("%d",&a[i]);
		for(i=1;i<=k;i++) scanf("%d",&b[i]);
		vector<ll> res;
		for(i=1;i<=q;i++)
		{
			scanf("%d",&d);
			p=upper_bound(a,a+1+k,d)-a;
			if(d==a[p-1]) res.push_back(b[p-1]);
			else res.push_back(b[p-1]+1LL*(d-a[p-1])*(b[p]-b[p-1])/(a[p]-a[p-1]));
		}
		for(i=0;i<q;i++) printf("%lld%c",res[i]," \n"[i==q-1]);
	}
	return 0;
}
