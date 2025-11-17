#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
void work_first()
{
	int n,i,j,x;
	scanf("%d",&n);
	string res;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(j=0;j<10;j++)
		{
			res+='a'+x%26;
			x/=26;
		}
	}
	cout<<res<<"\n";
}
void work_second()
{
	int i,j;
	ll sd,x;
	string s;
	cin>>s;
	vector<ll> res;
	for(i=0;i<s.size();i+=10)
	{
		sd=1;
		x=0;
		for(j=0;j<10;j++)
		{
			x+=sd*(s[i+j]-'a');
			sd*=26;
		}
		res.push_back(x);
	}
	printf("%d\n",res.size());
	for(i=0;i<res.size();i++) printf("%lld%c",res[i]," \n"[i+1==res.size()]);
}
int main()
{
	string tmp;
	cin>>tmp;
	if(tmp=="first") work_first();
	else work_second();
	return 0;
}
