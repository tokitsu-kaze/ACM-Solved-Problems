#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e3+10;
int main()
{
	int n,m,i,j,x,ok;
	scanf("%d%d",&n,&m);
	vector<int> c;
	set<int> s;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		c.push_back(x);
		s.insert(x);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&x);
		c.push_back(x);
	}
	sort(c.begin(),c.end());
	ok=0;
	for(i=0;i+1<c.size();i++)
	{
		if(s.count(c[i])&&s.count(c[i+1])) ok=1;
	}
	puts(ok?"Yes":"No");
	return 0;
}
