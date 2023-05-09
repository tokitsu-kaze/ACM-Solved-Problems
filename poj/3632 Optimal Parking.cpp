#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 100000000+10
using namespace std;
typedef long long ll;
int main()
{
    int t,n,i,a[101];
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			mem(a,0);
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			sort(a,a+n);
			cout<<(a[n-1]-a[0])*2<<endl;
		}
    }
    return 0;
} 