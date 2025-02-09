#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int MAX=5000+10;
int main()
{
	int i;
	string s;
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='N') s[i]='S';
		else if(s[i]=='S') s[i]='N';
		else if(s[i]=='E') s[i]='W';
		else if(s[i]=='W') s[i]='E';
	}
	cout<<s<<"\n";
	return 0;
}

