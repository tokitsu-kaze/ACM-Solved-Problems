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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-12
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
const ll mod=1000003;
ll ans;
void pow2(ll a,ll b)
{
	int s=1;
	while(b)
	{
		if(b&1) s=s*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	ans+=s;
}
int main()
{
	ll i;
	char c[111],a[511],*end;
	while(gets(c))
	{
		mem(a,0);
		for(i=0;i<strlen(c);i++)
		{
			switch(c[i])
			{
				case '>':strcat(a,"1000");break;
				case '<':strcat(a,"1001");break;
				case '+':strcat(a,"1010");break;
				case '-':strcat(a,"1011");break;
				case '.':strcat(a,"1100");break;
				case ',':strcat(a,"1101");break;
				case '[':strcat(a,"1110");break;
				case ']':strcat(a,"1111");break;
			}
		}
		reverse(a,a+strlen(a));
		ans=0;
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]=='1')
			{
				pow2(2,i);
				ans%=mod;
			}
		}
		printf("%d\n",ans%mod);
	}
    return 0;
}