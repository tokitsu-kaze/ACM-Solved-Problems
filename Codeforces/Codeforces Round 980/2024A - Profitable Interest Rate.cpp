#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int main()
{
	int T,a,b,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		if(a>=b) printf("%d\n",a);
		else printf("%d\n",max(0,a-(b-a)));
	}
	return 0;
}
/*
a-x>=b-2x
b-a<=x
*/

