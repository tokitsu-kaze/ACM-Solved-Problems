#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<20)+10;
int main()
{
	int T,a,b,c,d;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a>max(c,d) && b>max(c,d)) puts("NO");
		else if(c>max(a,b) && d>max(a,b)) puts("NO");
		else puts("YES");
	}
	return 0;
}

