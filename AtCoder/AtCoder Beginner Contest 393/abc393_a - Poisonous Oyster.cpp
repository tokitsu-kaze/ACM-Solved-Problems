#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int MAX=2e5+10;
int main()
{
	string a,b;
	cin>>a>>b;
	if(a=="fine" && b=="fine") puts("4");
	else if(a=="fine" && b=="sick") puts("3");
	else if(a=="sick" && b=="fine") puts("2");
	else puts("1");
	return 0;
}
