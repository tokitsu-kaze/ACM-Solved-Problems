#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		n=s.size();
		if(s=="()")
		{
			puts("NO");
			continue;
		}
		string res;
		res="";
		while(res.size()<2*n) res+="()";
		if(res.find(s)==res.npos)
		{
			puts("YES");
			cout<<res<<"\n";
			continue;
		}
		res="";
		while(res.size()<n) res+='(';
		while(res.size()<2*n) res+=')';
		puts("YES");
		cout<<res<<"\n";
	}
	return 0;
}
