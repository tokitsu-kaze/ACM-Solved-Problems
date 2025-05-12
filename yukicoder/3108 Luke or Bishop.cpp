#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int x,y;
	cin>>x>>y;
	if(x==0 && y==0) puts("0");
	else if(abs(x)==abs(y)) puts("1");
	else if(x==0||y==0) puts("1");
	else puts("2");
	return 0;
}
