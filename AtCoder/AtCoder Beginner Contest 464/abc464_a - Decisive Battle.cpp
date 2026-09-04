#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int main()
{
	string s;
	int cnte,cntw;
	cnte=cntw=0;
	cin>>s;
	for(auto &ch:s)
	{
		if(ch=='E') cnte++;
		else if(ch=='W') cntw++;
	}
	if(cnte>cntw) puts("East");
	else puts("West");
	return 0;
}
