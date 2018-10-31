#include<bits/stdc++.h>
using namespace std;
int main()
{
	/*string s="oMl";
	for(auto i:s)
	{
		cout<<abs(i-'z')<<endl;
	}*/
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string l;
		string s;
		cin>>l>>s;
		string output;
		for(auto i:s)
		{
			char ss[50];
			sprintf(ss,"%02d",abs(l[0]-i));
			ss[3]='\0';
			output+=string(ss);
		}

		while(output.size()!=0 && (*output.begin()=='0'))
			output.erase(output.begin());
		cout<<max((int)output.size(),1)<<endl;

	}


}
