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
char a[MAX];
int main()
{
	int len,i,j,k,flag;
	while(~scanf("%s",a+1))
	{
		len=strlen(a+1);
		for(i=1;i<=len/2;i++)
		{
			if(len%i==0)
			{
				int flag=0;
				k=1;
				for(j=i+1;j<=len;j++)
				{
					if(a[k]!=a[j])
					{
						flag=1;
						break;
					}
					k++;
					if(k>i) k=1;
				}
				if(!flag)
				{
					puts("Win");
					goto end;
				}
			}
		}
		puts("Lost");
		end:;
	}
	return 0;
} 