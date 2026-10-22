#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX];
void gao(int x)
{
	printf("%d %d\n",x,x+2);
	printf("%d %d\n",x+1,x+3);
	printf("%d %d\n",x,x+1);
	printf("%d %d\n",x+1,x+3);
	printf("%d %d\n",x+2,x+3);
	printf("%d %d\n",x,x+2);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=2) return 0*puts("No");
	if(n==3)
	{
		if(a[1]==a[2] && a[2]==a[3])
		{
			puts("Yes");
			puts("1");
			puts("1 3");
		}
		else puts("No");
		return 0;
	}
	puts("Yes");
	printf("%d\n",(n+3)/4*6);
	for(i=1;i+3<=n;i+=4) gao(i);
	if(n%4) gao(n-3);
	return 0;
}
