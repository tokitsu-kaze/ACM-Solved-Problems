#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;
int main()  
{  
    int x,n,i;  
    while(cin>>n)  
    {
        for(i=0;i<n;i++)
        {
			cin>>x;
			cout<<x*x-3*x+1<<endl;
			if(i!=n-1) cout<<endl;
		}
    }  
    return 0;
} 