#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	string s="HelloWorld";
	int x;
	scanf("%d",&x);
	string res="";
	for(int i=0;i<s.size();i++)
	{
		if(i+1==x) continue;
		res+=s[i];
	}
	cout<<res<<"\n";
	return 0;
}
