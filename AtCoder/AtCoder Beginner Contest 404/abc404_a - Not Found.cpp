#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int i;
	string s;
	cin>>s;
	for(i=0;i<26;i++)
	{
		if(s.find(i+'a')==s.npos)
		{
			cout<<char(i+'a')<<"\n";
			break;
		}
	}
	return 0;
}
