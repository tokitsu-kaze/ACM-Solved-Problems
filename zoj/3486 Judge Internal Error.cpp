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
using namespace std;
typedef long long ll;
int main()
{
	int t,n,i,a,max,temp;
	map<int,int> m;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			m.clear();
			max=0;
			for(i=0;i<n;i++)
			{
				scanf("%d",&a);
				m[a]++;
			}
			for(i=1001;i<=9999;i++)
			{
				if(m[i]>=max)
				{
					max=m[i];
					temp=i;
				}
			}
			cout<<temp<<endl;
		} 
	}
	return 0;
}