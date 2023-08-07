#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double eps=1e-4;
const int MAX=1e4+10;
const ll mod=1e9+7;
int main()
{
	int cnt;
	float x;
	while(cin>>x)
	{
		cnt=0;
		while(abs(x)>=2.0) x/=2.0,cnt++;
		while(abs(x)<1.0) x*=2.0,cnt--;
		cout<<cnt<<" "<<fixed<<setprecision(6)<<x<<endl;
	}
	return 0;
 }
