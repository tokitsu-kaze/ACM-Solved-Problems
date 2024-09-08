#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int x,y;
	cin>>x>>y;
	if(x+y==2||x+y==0) puts("Invalid");
	else if(x==1) puts("Yes");
	else puts("No");
	return 0;
}
