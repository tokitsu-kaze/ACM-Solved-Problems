#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	string s,res;
	cin>>s;
	res="";
	for(auto &it:s)
	{
		if(it=='2') res+='2';
	}
	cout<<res<<"\n";
	return 0;
}
