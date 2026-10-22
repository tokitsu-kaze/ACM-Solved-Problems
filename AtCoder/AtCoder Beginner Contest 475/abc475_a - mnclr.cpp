#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int i;
	string s,res;
	cin>>s;
	res="";
	res+=s[0];
	for(i=1;i<s.size();i++)
	{
		res+="o";
		res+=s[i];
	}
	cout<<res<<"\n";
	return 0;
}
