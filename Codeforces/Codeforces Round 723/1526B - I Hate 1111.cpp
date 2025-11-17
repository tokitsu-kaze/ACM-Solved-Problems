#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=300+10;
int main()
{
	int T,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&x);
		if(x%11==0 || x%111==0) puts("YES");
		else
		{
			x-=(x%11)*111;
			if(x>=0 && x%11==0) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
