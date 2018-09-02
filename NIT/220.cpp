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
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e4+10;
const ll mod=1e6;
char a[MAX];
int m,len;
bool check(int x)
{
	int i,cnt=1,now=0;
	for(i=0;i<len;i++)
	{
		if(a[i]>x) return 0;
		if(now+a[i]>x)
		{
			cnt++;
			now=a[i];
		}
		else now+=a[i];
	}
//	cout<<cnt<<endl;
	return cnt<=m;
}
int main()
{
	int l,r,mid;
	while(~scanf("%s",a))
	{
		len=strlen(a);
		scanf("%d",&m);
		l=0;
		r=2e7;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",r);
	}
	return 0;
}