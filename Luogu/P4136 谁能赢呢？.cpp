#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		if(n&1) puts("Bob");
		else puts("Alice");
	}
	return 0;
}
