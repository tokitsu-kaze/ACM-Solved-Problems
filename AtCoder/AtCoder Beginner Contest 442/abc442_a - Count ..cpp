#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	string s;
	int cnt;
	cin>>s;
	cnt=0;
	for(auto &it:s)
	{
		if(it=='i' || it=='j') cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
