#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
string add(string a,string b)
{
	int i,now;
	string res;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	if(a.size()>b.size()) swap(a,b);
	now=0;
	res="";
	for(i=0;i<a.size();i++)
	{
		now=now+a[i]-'0'+b[i]-'0';
		res.push_back(now%10+'0');
		now/=10;
	}
	for(i=a.size();i<b.size();i++)
	{
		now=now+b[i]-'0';
		res.push_back(now%10+'0');
		now/=10;
	}
	while(now)
	{
		res.push_back(now%10+'0');
		now/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}
int main()
{
	string a,b;
	cin>>a>>b;
	cout<<add(a,b)<<"\n";
	return 0;
}
