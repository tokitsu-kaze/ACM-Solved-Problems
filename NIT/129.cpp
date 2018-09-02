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
    int n,a,b,c; 
    while(cin>>n)  
    {
        while(n--)
        {
			cin>>a>>b>>c;
			if((double)a/(a+b)*(double)a/(a+b+c)+(double)b/(a+b)*(double)b/(a+b+c)>=0.5) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			if(n) cout<<endl;
		}
    }  
    return 0;
} 