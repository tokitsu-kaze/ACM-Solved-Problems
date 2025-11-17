#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3000+10;
int main()
{
	int n,l,r,i,cnt,x,y;
	scanf("%d%d%d",&n,&l,&r);
	cnt=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if(l>=x && r<=y) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
