#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int main()
{
	int T,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&y);
		if(__gcd(x,y)>1) puts("0");
		else if(__gcd(x+1,y)>1) puts("1");
		else if(__gcd(x,y+1)>1) puts("1");
		else puts("2");
	}
	return 0;
}
