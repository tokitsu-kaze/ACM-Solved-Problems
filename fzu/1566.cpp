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
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int t,i,s;
	char a[11111];
	map<char,int> mp;
	mp['I']=1;
	mp['V']=5;
	mp['X']=10;
	mp['L']=50;
	mp['C']=100;
	mp['D']=500;
	mp['M']=1000;
	while(~scanf("%d",&t))
	{
		getchar();
		while(t--)
		{
			scanf("%s",a);
			s=0;
			for(i=0;i<strlen(a)-1;i++)
			{
				if(mp[a[i]]>=mp[a[i+1]])s+=mp[a[i]];
				else s-=mp[a[i]];
			}
			s+=mp[a[strlen(a)-1]];
			printf("%d\n",s);
		}
	}
	return 0;
}