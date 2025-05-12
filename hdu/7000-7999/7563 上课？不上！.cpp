#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T,h1,t1,h2,t2;
	cin>>T;
	while(T--)
	{
		cin>>h1>>t1>>h2>>t2;
		t1+=h1*60;
		t2+=h2*60;
		if(t2-t1>90) puts("sad");
		else puts("happy");
	}
	return 0;
}
