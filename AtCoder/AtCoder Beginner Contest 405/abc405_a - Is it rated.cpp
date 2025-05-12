#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int r,x;
	cin>>r>>x;
	if(x==1)
	{
		if(r>=1600 && r<=2999) puts("Yes");
		else puts("No");
	}
	else
	{
		if(r>=1200 && r<=2399) puts("Yes");
		else puts("No");
	}
	return 0;
}
