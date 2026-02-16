#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=8e5+10;
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(i==n/2) continue;
		printf("%c",s[i]);
	}
	puts("");
	return 0;
}
