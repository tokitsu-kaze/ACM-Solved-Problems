#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	if(s[0]==s[2]) puts("Yes");
	else puts("No");
	return 0;
}
