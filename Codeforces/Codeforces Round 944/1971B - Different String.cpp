#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
int main()
{
	int t,n;
	string s,tmp;
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		tmp=s;
		sort(tmp.begin(),tmp.end());
		if(tmp[0]==tmp.back())
		{
			puts("NO");
			continue;
		}
		if(tmp==s) reverse(tmp.begin(),tmp.end());
		puts("YES");
		cout<<tmp<<"\n";
	}
	return 0;
}
