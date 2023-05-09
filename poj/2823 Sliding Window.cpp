#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
/***************************************  head  **********************************************/
int a[MAX],res[2][MAX],dq[2][MAX<<1],l[2],r[2];
int main()
{
	int n,k,i,j;
	while(~scanf("%d%d",&n,&k))
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		mem(l,0);
		mem(r,0);
		for(i=0,j=0;i+k-1<n;i++)
		{
			while(j<i+k)
			{
				while(r[0]-l[0]&&a[dq[0][r[0]-1]]>a[j]) r[0]--;
				while(r[1]-l[1]&&a[dq[1][r[1]-1]]<a[j]) r[1]--;
				dq[0][r[0]++]=j;
				dq[1][r[1]++]=j;
				j++;
			}
			while(r[0]-l[0]&&dq[0][l[0]]<i) l[0]++;
			while(r[1]-l[1]&&dq[1][l[1]]<i) l[1]++;
			res[0][i]=a[dq[0][l[0]]];
			res[1][i]=a[dq[1][l[1]]];
		}
		for(i=0;i<=n-k;i++) printf("%d%c",res[0][i]," \n"[i==n-k]);
		for(i=0;i<=n-k;i++) printf("%d%c",res[1][i]," \n"[i==n-k]);
	}
	return 0;
}