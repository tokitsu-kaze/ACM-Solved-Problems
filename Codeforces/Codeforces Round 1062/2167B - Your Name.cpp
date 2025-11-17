#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e6+10;
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		string s,t;
		cin>>n;
		cin>>s>>t;
		sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		if(s==t) puts("YES");
		else puts("NO");
	}
	return 0;
}
