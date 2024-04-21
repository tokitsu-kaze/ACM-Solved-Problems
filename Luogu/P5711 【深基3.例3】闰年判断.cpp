#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if(n%400==0||(n%100!=0&&n%4==0)) puts("1");
	else puts("0");
	return 0;
}
