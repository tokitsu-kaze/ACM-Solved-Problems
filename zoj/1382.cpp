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
    int t,n,cnt; 
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			cnt=0;
			while(1)
			{
				if(n%2==0)
				{
					n>>=1;
					cnt++;
				}
				else break;
			}
			cout<<n<<" "<<cnt<<endl;
		}
	}
    return 0;
}