#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	printf("%d\n",(n+y/x-1)/(y/x));
	return 0;
}

