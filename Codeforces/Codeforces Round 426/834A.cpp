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
int main()
{
	int n,temp,i,flag1,flag2;
	char a[33],b[33];
	map<char,int> mp;
	mp['^']=1;
	mp['>']=2;
	mp['v']=3;
	mp['<']=4;
	while(~scanf("%s %s",&a,&b))
	{
		flag1=flag2=0;
		scanf("%d",&n);
		n%=4;
		if(n==0) n=4;
		temp=mp[a[0]];
		for(i=0;i<n;i++)
		{
			temp=(temp+1)%4;
		}
		if(temp==0) temp=4;
		if(mp[b[0]]==temp) flag1=1;
		temp=mp[a[0]];
		for(i=0;i<n;i++)
		{
			temp=(temp-1+4)%4;
		}
		if(temp==0) temp=4;
		if(mp[b[0]]==temp) flag2=1;
		if(flag1+flag2==2||flag1+flag2==0) puts("undefined");
		else if(flag1) puts("cw");
		else puts("ccw");
	}
	return 0;
}
/*
^ >
1
< ^
3
^ v
6

*/