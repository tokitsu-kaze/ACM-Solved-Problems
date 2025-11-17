#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;
	int ok;
	cin>>s;
	ok=1;
	for(auto &it:s)
	{
		if(it=='#') ok=1;
		else if(it=='.')
		{
			if(ok)
			{
				it='o';
				ok=0;
			}
		}
	}
	cout<<s<<"\n";
	return 0;
}
