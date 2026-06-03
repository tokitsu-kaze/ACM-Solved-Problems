#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int n,l,r,i,x,mx,p;
	scanf("%d%d%d",&n,&l,&r);
	mx=-1;
	p=-1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x<l||x>r) continue;
		if(x>mx)
		{
			mx=x;
			p=i;
		}
	}
	printf("%d\n",p);
	return 0;
}
