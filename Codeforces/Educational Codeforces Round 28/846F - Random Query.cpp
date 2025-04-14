#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int lst[MAX],a[MAX];
int main()
{
	int n,i;
	ll fz,fm;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(lst,0,sizeof lst);
	fz=0;
	for(i=1;i<=n;i++)
	{
		fz+=2LL*(i-lst[a[i]])*(n-i+1)-1;
		lst[a[i]]=i;
	}
	fm=1LL*n*n;
	printf("%.10f\n",1.0*fz/fm);
	return 0;
}
