#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,a,b,i;
	string s;
	cin>>n>>a>>b;
	cin>>s;
	while(a--) s.erase(s.begin());
	while(b--) s.pop_back();
	cout<<s<<"\n";
	return 0;
}
