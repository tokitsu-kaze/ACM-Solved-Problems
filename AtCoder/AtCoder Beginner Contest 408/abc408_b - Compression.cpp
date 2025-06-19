#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,x;
	set<int> s;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s.insert(x);
	}
	vector<int> res;
	for(auto &it:s) res.push_back(it);
	printf("%d\n",(int)res.size());
	for(i=0;i<res.size();i++) printf("%d%c",res[i]," \n"[i+1==(int)res.size()]);
	return 0;
}
