#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int main()
{
	int t,i,ok;
	scanf("%d",&t);
	string tmp="Yes";
	while(t--)
	{
		string s;
		cin>>s;
		for(i=0;i<3;i++)
		{
			if(tmp[i]==s[0]) break;
		}
		if(i==3)
		{
			puts("NO");
			continue;
		}
		ok=1;
		for(auto &ch:s)
		{
			if(ch!=tmp[i]) ok=0;
			i=(i+1)%3;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
