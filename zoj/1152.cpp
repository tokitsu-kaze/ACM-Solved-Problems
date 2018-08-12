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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{
    int t,n,m,cnt,i,j,k; 
    while(cin>>t)
    {
		while(t--)
		{
			k=1;
			while(cin>>n>>m)
			{
				if(!n&&!m) break;
				cnt=0;
				for(i=1;i<n-1;i++)
				{
					for(j=i+1;j<n;j++)
					{
						if((i*i+j*j+m)%(i*j)==0) cnt++;
					}
				}
				printf("Case %d: %d\n",k++,cnt);
			}
			if(t) puts("");
		}
	}
    return 0;
}