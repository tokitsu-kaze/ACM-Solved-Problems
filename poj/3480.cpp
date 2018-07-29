#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
using namespace std;
int main()
{
	int t,n,a,sum,flag;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			flag=sum=0;
			while(n--)
			{
				cin>>a;
				if(a>1) flag=1;
				sum^=a;
			}
			if(!flag)
			{
				if(sum) cout<<"Brother"<<endl;
				else cout<<"John"<<endl;
			}
			else
			{
				if(sum) cout<<"John"<<endl;
				else cout<<"Brother"<<endl;
			}
		}
	}
    return 0;
}