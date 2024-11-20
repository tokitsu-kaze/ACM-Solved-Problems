#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
int main()
{
	int t,a,b,c,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a>b) swap(a,b);
		if(c>d) swap(c,d);
		if(c>=a && c<=b && (d<a || d>b)) puts("YES");
		else if(a>=c && a<=d && (b<c || b>d)) puts("YES");
		else puts("NO");
	}
	return 0;
}
