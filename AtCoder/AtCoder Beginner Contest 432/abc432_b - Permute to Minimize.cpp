#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int i,p;
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	for(i=0;i<s.size();i++)
	{
		if(s[i]!='0')
		{
			p=i;
			break;
		}
	}
	while(p>0)
	{
		swap(s[p-1],s[p]);
		p--;
	}
	cout<<s<<"\n";
	return 0;
}
