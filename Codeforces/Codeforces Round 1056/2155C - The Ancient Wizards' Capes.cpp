#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int d[MAX],a[MAX],n;
int cal(int x)
{
	int i,l,r;
	d[1]=x;
	for(i=2;i<=n;i++)
	{
		d[i]=-(a[i]-a[i-1])+1-d[i-1];
		if(d[i]!=0 && d[i]!=1) return 0;
	}
	r=0;
	for(i=n;i;i--) r+=d[i];
	l=0;
	for(i=1;i<=n;i++)
	{
		r-=d[i];
		if(a[i]!=l+r+1) return 0;
//		cout<<x<<" "<<l<<" "<<r<<" "<<i<<endl;
		l+=1-d[i];
	}
	return 1;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		printf("%d\n",cal(0)+cal(1));
	}
	return 0;
}
/*
x y
a[i]=l[i-1]+r[i+2]+y+1
a[i+1]=l[i-1]+r[i+2]+(1-x)+1
*/

