#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	for(auto &it:s)
	{
		if(it>='A'&&it<='Z') it=it-'A'+'a';
		if(it=='_') it='-';
	}
	s="solution-"+s;
	cout<<s<<"\n";
	return 0;
}
