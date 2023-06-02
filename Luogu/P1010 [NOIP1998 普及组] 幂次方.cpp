#include <bits/stdc++.h>
using namespace std;
string dfs(int x)
{
	int i;
	vector<string> res;
	for(i=16;~i;i--)
	{
		if(((x>>i)&1)==0) continue;
		if(i==0) res.push_back("2(0)");
		else if(i==1) res.push_back("2");
		else res.push_back("2("+dfs(i)+")");
	}
	string ans=res[0];
	for(i=1;i<res.size();i++) ans+="+"+res[i];
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	cout<<dfs(n)<<"\n";
	return 0;
}
