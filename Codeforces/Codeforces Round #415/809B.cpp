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
const int MAX=1e5+10;
const ll mod=1e9+7;
bool check(int x,int y)
{
	char a[11];
	printf("1 %d %d\n",x,y);
	fflush(stdout);
	scanf("%s",a);
	return strcmp(a,"TAK")==0;
}
int search(int l,int r)
{
	int mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid,mid+1)) r=mid;
		else l=mid+1;
	}
	return l;
}
int main()
{
	int n,k,ans1,ans2;
	scanf("%d%d",&n,&k);
	ans1=search(1,n);
	if(ans1==1) ans2=search(2,n);
	else if(ans1==n) ans2=search(1,n-1);
	else
	{
		ans2=search(1,ans1-1);
		if(!check(ans2,ans1)) ans2=search(ans1+1,n);
	}	
	printf("2 %d %d\n",ans1,ans2);
	fflush(stdout);
	return 0;
}