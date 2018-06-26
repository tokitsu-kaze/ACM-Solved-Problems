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
const ll mod=1e9+7;
const int MAX=(int)1e5+10;
int main()
{
	int a,b,i,cnt,flag,tag;
	char temp[111],ans[111];
	while(~scanf("%d%d",&a,&b))
	{
		tag=0;
		a-=b;
		if(a<0)
		{
			tag=1;
			a*=-1;
		}
		sprintf(temp,"%d",a);
		cnt=0;
		flag=0;
		for(i=strlen(temp)-1;i>=0;i--)
		{
			ans[cnt++]=temp[i];
			flag++;
			if(i&&flag%3==0) ans[cnt++]=',';
		}
		ans[cnt]='\0';
		reverse(ans,ans+cnt);
		if(tag) putchar('-');
		puts(ans);
	}
	return 0;
}