#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int x,y,i,j,fz,fm;
	scanf("%d%d",&x,&y);
	fz=fm=0;
	for(i=1;i<=6;i++)
	{
		for(j=1;j<=6;j++)
		{
			if(i+j>=x || abs(i-j)>=y) fz++;
			fm++;
		}
	}
	printf("%.10f\n",1.0*fz/fm);
	return 0;
}
