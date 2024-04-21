#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x,a,b;
	scanf("%d",&x);
	if(x%2==0) a=1;
	else a=0;
	if(x>4&&x<=12) b=1;
	else b=0;
	printf("%d %d %d %d\n",a&b,a|b,a^b,!(a|b));
	return 0;
}
