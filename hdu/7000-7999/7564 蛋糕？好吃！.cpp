#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int ans[11][11]={
{},{},{},{},
{0,0,4},
{0,0,11,11},
{0,0,13,6,13},
{0,0,15,22,22,15},
{0,0,17,25,8,25,17},
{0,0,19,28,37,37,28,19},
{0,0,21,31,41,10,41,31,21},
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		cout<<ans[n][k]<<endl;
	}
	return 0;
}
