#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,h,m;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	m=(c*60+d)-(a*60+b);
	h=m/60;
	m%=60;
	printf("%d %d\n",h,m);
	return 0;
}
