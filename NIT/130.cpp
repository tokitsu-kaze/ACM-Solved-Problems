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
    int n,a,b,c,d,e,f,i; 
    while(cin>>n)  
    {
        while(n--)
        {
			cin>>a>>b>>c>>d;
			if(b==d)
			{
				e=a+c;
				f=b;
			}
			else
			{
				e=a*d+c*b;
				f=b*d;
			}
			if(e%f==0) cout<<e/f<<endl;
			else
			{
				for(i=2;i<=min(e,f);)
				{
					if(e%i==0&&f%i==0)
					{
						e/=i;
						f/=i;
					}
					else i++;
				}
				cout<<e<<"/"<<f<<endl;
			}
			if(n) cout<<endl;
		}
    }  
    return 0;
} 