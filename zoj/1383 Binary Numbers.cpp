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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 1000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
    int t,n,cnt,i,ans[111];
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			mem(ans,0);
			i=cnt=0;
			while(n)
			{
				if(n&1)
				{
					ans[cnt++]=i;
				}
				n>>=1;
				i++;
			}
			for(i=0;i<cnt;i++)
			{
				cout<<ans[i];
				if(i!=cnt-1) cout<<" ";
				else puts("");
			}
		}
	}
    return 0;
}