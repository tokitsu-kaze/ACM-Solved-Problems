#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int main()
{
	int t,x,y,k,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&x,&y,&k);
		if(k&1)
		{
			printf("%d %d\n",x,y);
			k--;
		}
		for(i=1;i<=k;i++)
		{
			if(i&1) printf("%d %d\n",x-(i+1)/2,y);
			else printf("%d %d\n",x+(i+1)/2,y);
		}
	}
	return 0;
}
