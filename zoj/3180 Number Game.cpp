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
	int t,i,j,flag,flag1,end[3],begin[3],check[3][3];
	while(cin>>t)
	{
		while(t--)
		{
			cin>>end[0]>>end[1]>>end[2];
			cin>>begin[0]>>begin[1]>>begin[2];
			sort(end,end+3);
			sort(begin,begin+3);
			
			check[0][0]=begin[0];
			check[0][1]=begin[1];
			check[0][2]=begin[0]+begin[1]-1;
			
			sort(check[0],check[0]+3);
			check[1][0]=begin[1];
			check[1][1]=begin[2];
			check[1][2]=begin[1]+begin[2]-1;
			sort(check[1],check[1]+3);
			
			check[2][0]=begin[0];
			check[2][1]=begin[2];
			check[2][2]=begin[0]+begin[2]-1;
			sort(check[2],check[2]+3);
			
			while(1)
			{
				for(i=0,flag1=0;i<3;i++)
				{
					for(j=0,flag=0;j<3;j++)
					{
						if(end[j]!=check[i][j])
						{
							flag=1;
							break;
						}
					}
					if(!flag)
					{
						puts("Yes");
						flag1=1;
						break;
					}
				}
				if(flag1) break;
				if(end[0]<begin[0])
				{
					puts("No");
					break;
				}
				end[2]=end[1]-end[0]+1;
				sort(end,end+3);
			}
		}
	}
	return 0;
}