#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int n,i;
	string s;
	vector<string> res;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		res.push_back(s);
	}
	sort(res.begin(),res.end(),[](string x,string y){
		return x.size()<y.size();
	});
	string ans="";
	for(auto &it:res) ans+=it;
	cout<<ans<<"\n";
	return 0;
}
