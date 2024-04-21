#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
string sub(string a,string b)
{
	int i,f,now;
	if(a.size()<b.size() || (a.size()==b.size() && a<b))
	{
		swap(a,b);
		f=1;
	}
	else f=0;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	vector<int> tmp(a.size()+1,0);
	for(i=0;i<b.size();i++)
	{
		tmp[i]+=a[i]-b[i];
		if(tmp[i]<0)
		{
			tmp[i]+=10;
			tmp[i+1]--;
		}
	}
	for(i=b.size();i<a.size();i++)
	{
		tmp[i]+=a[i]-'0';
		if(tmp[i]<0)
		{
			tmp[i]+=10;
			tmp[i+1]--;
		}
	}
	while(tmp.size()>0 && tmp.back()==0) tmp.pop_back();
	reverse(tmp.begin(),tmp.end());
	string res;
	if(f) res="-";
	else res="";
	for(auto &it:tmp) res+='0'+it;
	if(res.size()==0) res="0";
	return res;
}
int main()
{
	string a,b;
	cin>>a>>b;
	cout<<sub(a,b)<<"\n";
	return 0;
}
