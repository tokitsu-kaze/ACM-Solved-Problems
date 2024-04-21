#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e3+10;
int main()
{
	int t;
	string s;
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		sort(s.begin(),s.end());
		printf("%c\n",s[2]);
	}
	return 0;
}
