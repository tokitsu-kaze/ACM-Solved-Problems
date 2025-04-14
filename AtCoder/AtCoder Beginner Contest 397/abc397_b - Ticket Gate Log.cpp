#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	string s,now;
	cin>>s;
	now="";
	for(auto &it:s)
	{
		if(it=='i')
		{
			if(now.size()>0 && now.back()=='i')
			{
				now+="o";
			}
			now+="i";
		}
		else
		{
			if(now.size()==0) now+="i";
			else if(now.size()>0 && now.back()=='o')
			{
				now+="i";
			}
			now+="o";
		}
	}
	if(now.size()&1)
	{
		assert(now.back()=='i');
		now+="o";
	}
	printf("%d\n",now.size()-s.size());
	return 0;
}
