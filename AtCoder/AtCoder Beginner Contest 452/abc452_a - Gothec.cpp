#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==1 && b==7) puts("Yes");
	else if(a==3 && b==3) puts("Yes");
	else if(a==5 && b==5) puts("Yes");
	else if(a==7 && b==7) puts("Yes");
	else if(a==9 && b==9) puts("Yes");
	else puts("No");
	return 0;
}
