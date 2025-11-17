#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int x,y,z;
	scanf("%d%d",&x,&y);
	z=x+y;
	if(z>12) z-=12;
	printf("%d\n",z);
	return 0;
}
