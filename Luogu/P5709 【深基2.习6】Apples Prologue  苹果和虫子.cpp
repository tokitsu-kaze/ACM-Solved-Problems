#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,t,s;
	scanf("%d%d%d",&m,&t,&s);
	if(t==0) puts("0");
	else printf("%d\n",max(0,m-(s+t-1)/t));
	return 0;
}
