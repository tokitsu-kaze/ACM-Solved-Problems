#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	string s,ans;
	int n,i;
	cin>>s>>n;
	for(i=0;i<n;i++) s.pop_back();
	for(i=n;i<s.size();i++) ans+=s[i];
	cout<<ans<<"\n";
	return 0;
}
