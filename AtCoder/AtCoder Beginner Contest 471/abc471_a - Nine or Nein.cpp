#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int a,b,f;
	scanf("%d%d",&a,&b);
	f=0;
	f+=(a+b==9);
	f+=(a-b==9);
	f+=(a*b==9);
	f+=(a==9*b);
	if(f) puts("Nine");
	else puts("Nein");
	return 0;
}
