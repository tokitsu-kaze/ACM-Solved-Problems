#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a==b && a==c) puts("Yes");
	else
	{
		if(a+b==c || a+c==b || b+c==a) puts("Yes");
		else puts("No");
	}
	return 0;
}