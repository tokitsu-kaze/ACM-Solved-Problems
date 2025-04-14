#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int n,i;
	cin>>n;
	string res="";
	for(i=1;i<=(n-1)/2;i++) res+="-";
	if(n&1) res+="=";
	else res+="==";
	for(i=1;i<=(n-1)/2;i++) res+="-";
	cout<<res<<"\n";
	return 0;
}
