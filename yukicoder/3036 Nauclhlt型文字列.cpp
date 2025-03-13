#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int n,i;
	string s,a,b;
	cin>>n;
	cin>>s;
	if(n&1) return 0*puts("No");
	a="";
	b="";
	for(i=0;i<n;i++)
	{
		if(i&1) b+=s[i];
		else a+=s[i];
	}
	puts("Yes");
	cout<<a<<" "<<b<<"\n";
	return 0;
}
