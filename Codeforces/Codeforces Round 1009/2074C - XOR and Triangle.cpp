#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,x,y,i,ok1,ok2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&x);
		y=0;
		ok1=ok2=0;
		for(i=0;i<30;i++)
		{
			if((x>>i)&1)
			{
				if(!ok1) y|=(1<<i);
				ok1=1;
			}
			else
			{
				if(!ok2) y|=(1<<i);
				ok2=1;
			}
		}
		if(y<x && x+y>(x^y) && x+(x^y)>y && y+(x^y)>x) printf("%d\n",y);
		else puts("-1");
	}
	return 0;
}
