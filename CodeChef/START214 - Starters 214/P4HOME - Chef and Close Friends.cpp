#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int cal(int l,int r,int a,int b)
{
	return max(0,min(r,b)-max(l,a));
}
int main()
{
	int T,x,y,z;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&x,&y,&z);
		printf("%d\n",cal(x-y,x+y,x-z,x+z));
	}
	return 0;
}
