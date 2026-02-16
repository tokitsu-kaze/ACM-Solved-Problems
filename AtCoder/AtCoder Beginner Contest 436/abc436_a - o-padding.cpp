#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int n;
	string s;
	cin>>n>>s;
	while(s.size()<n) s="o"+s;
	cout<<s<<"\n";
	return 0;
}
