#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,ans,now;
	string s;
	cin>>s;
	ans=0;
	now=0;
	for(i=0;i<s.size();i++)
	{
		if(now+1<=i+1-(now+1))//ѡp
		{
			if(s[i]=='g') ans++;
			now++;
		}
		else
		{
			if(s[i]=='p') ans--;
		}
	}
	printf("%d\n",ans);
	return 0;
}
