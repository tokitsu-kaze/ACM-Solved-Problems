#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int a,b,x,y;
	double tmp;
	scanf("%d%d",&a,&b);
	tmp=1.0*a/b;
	x=a/b;
	y=a/b+1;
	if(tmp-x<y-tmp) printf("%d\n",x);
	else printf("%d\n",y);
	return 0;
}
