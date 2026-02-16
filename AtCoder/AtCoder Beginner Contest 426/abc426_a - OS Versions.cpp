#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	string x,y;
	cin>>x>>y;
	if(x==y) puts("Yes");
	else
	{
		if(x[0]=='S' && y[0]=='O') puts("Yes");
		else if(x[0]=='L' && (y[0]=='O'||y[0]=='S')) puts("Yes");
		else puts("No");
	}
	return 0;
}

