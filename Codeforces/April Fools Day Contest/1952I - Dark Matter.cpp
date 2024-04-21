#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	char s[105];
	scanf("%d%s%d",&a,s,&b);
	printf("%d\n",a+b+(a*a+b*b+(a-b)+abs(a)*2*b-(a*b+2)));
	return 0;
}
