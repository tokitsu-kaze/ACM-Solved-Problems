#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int a,b,i,cnt;
	scanf("%d%d",&a,&b);
	cnt=0;
	for(i=0;i<=255;i++)
	{
		if((a|i)==b) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}

