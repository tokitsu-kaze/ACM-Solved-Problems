#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
int main()
{  
    ll sum,n,m;  
    while(cin>>m)
	{
		while(m--)
		{
			cin>>n;	
            if(n<=2) sum=n;
            else if(n%2) sum=n*(n-1)*(n-2);
            else
            {
				if(n%3) sum=n*(n-1)*(n-3);
				else sum=(n-1)*(n-2)*(n-3);
			}
			cout<<sum<<endl;
		}
    }  
    return 0;  
} 