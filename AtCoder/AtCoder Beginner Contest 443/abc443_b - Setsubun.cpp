#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int main()
{
	int n,k,cnt,now;
	scanf("%d%d",&n,&k);
	cnt=0;
	now=n;
	while(now<k)
	{
		n++;
		cnt++;
		now+=n;
	}
	printf("%d\n",cnt);
	return 0;
}
