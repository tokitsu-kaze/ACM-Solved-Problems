#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int a,b,id;}a[MAX];
int main()
{
	int n,i;
	ll sa,sb;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i].a);
	for(i=1;i<=n;i++) scanf("%d",&a[i].b);
	for(i=1;i<=n;i++) a[i].id=i;
	sort(a+1,a+1+n,[](node x,node y){
		int rx=x.a+max(x.b,y.a)+y.b;
		int ry=y.a+max(y.b,x.a)+x.b;
		if(rx==ry) return x.a<y.a;
		return rx<ry;
	});
	sa=sb=0;
	for(i=1;i<=n;i++)
	{
		sa+=a[i].a;
		sb=max(sa,sb)+a[i].b;
	}
	printf("%lld\n",sb);
	for(i=1;i<=n;i++) printf("%d%c",a[i].id," \n"[i==n]);
	return 0;
}
