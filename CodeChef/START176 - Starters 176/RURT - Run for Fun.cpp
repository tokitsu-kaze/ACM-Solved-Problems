#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d\n",max(0,(y+x-1)/x-1));
	return 0;
}
