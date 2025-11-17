#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[12];
vector<string> res;
int n,k;
void dfs(int cnt,string now)
{
	int i;
	if(cnt==k)
	{
		res.push_back(now);
		return;
	}
	for(i=0;i<n;i++) dfs(cnt+1,now+s[i]);
}
int main()
{
	int x,i;
	cin>>n>>k>>x;
	for(i=0;i<n;i++) cin>>s[i];
	res.clear();
	dfs(0,"");
	sort(res.begin(),res.end());
	cout<<res[x-1]<<"\n";
	return 0;
}
