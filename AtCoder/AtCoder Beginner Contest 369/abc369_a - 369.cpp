#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int main()
{
	int a,b;
	cin>>a>>b;
	if(a>b) swap(a,b);
	if(a-b==0) puts("1");
	else if((a-b)%2==0) puts("3");
	else puts("2");
	return 0;
}
