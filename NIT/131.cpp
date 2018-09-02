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
    int n,m,i,a[1010],max,sum,first,end,temp; 
    while(cin>>m)  
    {
        while(m--)
        {
			cin>>n;
			sum=0;
			max=INT_MIN;
			for(i=1;i<=n;i++)
			{
				scanf("%d",&a[i]);
			}
			temp=1;
			for(i=1;i<=n;i++)
			{
				sum+=a[i];
				if(sum>max)
				{
					max=sum;
					first=temp;
					end=i;
				}
				if(sum<=0)
				{
					sum=0;
					temp=i+1;
				}
			}
			if(max<=0) printf("0 0 0\n");
			else printf("%d %d %d\n",max,first,end);
			if(m) cout<<endl;
		}
    }  
    return 0;
} 