#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],c[MAX],d[MAX],n;
int cal(int x,int *y)
{
	int i,pos,res;
	pos=lower_bound(y+1,y+1+n,x)-y;
	res=INF;
	for(i=max(1,pos-1);i<=min(n,pos+1);i++)
	{
		res=min(res,abs(x-y[i]));
	}
	return res;
}
int main()
{
	int T,i,a1,an,b1,bn;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=n;i++)
		{
			c[i]=a[i];
			d[i]=b[i];
		}
		sort(c+1,c+1+n);
		sort(d+1,d+1+n);
		a1=cal(a[1],d);
		an=cal(a[n],d);
		b1=cal(b[1],c);
		bn=cal(b[n],c);
		ans=LLINF;
		ans=min(ans,0LL+a1+an+b1+bn);
		ans=min(ans,0LL+abs(a[1]-b[1])+an+bn);
		ans=min(ans,0LL+abs(a[n]-b[n])+a1+b1);
		ans=min(ans,0LL+abs(a[1]-b[1])+abs(a[n]-b[n]));
		ans=min(ans,0LL+abs(a[1]-b[n])+an+b1);
		ans=min(ans,0LL+abs(a[n]-b[1])+a1+bn);
		ans=min(ans,0LL+abs(a[1]-b[n])+abs(a[n]-b[1]));
		printf("%lld\n",ans);
	}
	return 0;
}

