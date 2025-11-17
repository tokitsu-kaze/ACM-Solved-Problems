#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&x);
/*		for(y=2*x;;y++)
		{
			string tmp=to_string(x)+to_string(y);
			if(stoll(tmp)%(x+y)==0)
			{
				printf("%d\n",y);
				break;
			}
		}*/
		printf("%d\n",2*x);
	}
	return 0;
}
