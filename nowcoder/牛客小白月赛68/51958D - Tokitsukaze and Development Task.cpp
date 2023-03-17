#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;
typedef vector<VPII> VVPII;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/********************************* std-head *********************************/
int res[333],dir[6]={1,-1,10,-10,100,-100};
void bfs()
{
	int i,t,nex;
	mem(res,0x3f);
	res[10]=0;
	queue<int> q;
	q.push(10);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<6;i++)
		{
			nex=t+dir[i];
			nex=max(10,nex);
			nex=min(300,nex);
			if(res[nex]<=res[t]+1) continue;
			res[nex]=res[t]+1;
			q.push(nex);
		}
		if(res[300]>res[t]+1)
		{
			res[300]=res[t]+1;
			q.push(300);
		}
	}
//	for(i=10;i<=300;i++) cout<<i<<" "<<res[i]<<endl;
}
int main()
{
	bfs();
	int a,b,c,d;
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",res[a]+res[b]+res[c]+res[d]);
	}
	return 0;
}


