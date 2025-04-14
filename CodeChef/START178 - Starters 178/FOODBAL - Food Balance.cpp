#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	e=abs(a-b);
	f=abs(c-d);
	if(e<f) puts("First");
	else if(e==f) puts("Both");
	else puts("Second");
	return 0;
}
