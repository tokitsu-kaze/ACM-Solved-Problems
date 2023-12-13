#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	string s,res;
	map<string,int> mp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		mp[s]++;
	}
	res="uh-oh";
	for(auto &it:mp)
	{
		if(it.second*2>n)
		{
			res=it.first;
			break;
		}
	}
	cout<<res<<"\n";
	return 0;
}
