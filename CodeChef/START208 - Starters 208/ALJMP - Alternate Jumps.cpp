#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,f,pos;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		pos=n;
		f=0;
		for(i=n-1;i;i--)
		{
			if(f&1) pos+=i;
			else pos-=i;
			f^=1;
		}
		printf("%d\n",pos);
	}
	return 0;
}
