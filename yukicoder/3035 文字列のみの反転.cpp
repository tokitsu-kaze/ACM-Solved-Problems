#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int main()
{
	string s,a,b;
	cin>>s;
	a="";
	b="";
	for(auto &it:s)
	{
		if(it>='a' && it<='z') a+=it;
		else b+=it;
	}
	reverse(a.begin(),a.end());
	cout<<a+b<<"\n";
	return 0;
}
