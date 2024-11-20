#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
int main()
{
	int t,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		printf("%d %d\n",x,y);
	}
	return 0;
}
