#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=50000+10;
int main()
{
	int T,a,b,c,d;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(min(a,c)>=min(b,d)) puts("Gellyfish");
		else puts("Flower");
	}
	return 0;
}
