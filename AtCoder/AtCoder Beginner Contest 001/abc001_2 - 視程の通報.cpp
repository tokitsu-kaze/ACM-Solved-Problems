#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int n;
	scanf("%d",&n);
	if(n<100) puts("00");
	else if(n<=5000) printf("%02d\n",n/100);
	else if(n<=30000) printf("%02d\n",n/1000+50);
	else if(n<=70000) printf("%02d\n",(n/1000-30)/5+80);
	else puts("89");
	return 0;
}
