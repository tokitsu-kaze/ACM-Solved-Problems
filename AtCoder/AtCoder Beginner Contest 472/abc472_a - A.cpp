#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	string s;
	cin>>s;
	for(auto &it:s)
	{
		if(it!='A') it='.';
	}
	cout<<s<<"\n";
	return 0;
}
