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
#define MAX 10000000+10
using namespace std;
typedef long long ll;
int ans[MAX];
int main()
{
    int t,n,i;
    double s;
    mem(ans,0);
    s=0;
    for(i=1;i<MAX;i++)
    {
		s+=log10(i*1.0);
		ans[i]=int(s)+1;
	}
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			cout<<ans[n]<<endl;
		}
	} 
    return 0;
}