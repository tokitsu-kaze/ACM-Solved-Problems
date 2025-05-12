#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char mp[44][44];
int main()
{
	int T,n,h,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d:%d",&h,&m);
		if(h<=11)
		{
			if(h==0) h=12;
			printf("%02d:%02d AM\n",h,m);
		}
		else
		{
			if(h>12) h-=12;
			printf("%02d:%02d PM\n",h,m);
		}
	}
	return 0;
}
