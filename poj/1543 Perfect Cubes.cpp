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
#include <vector>
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 50000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int i,a,b,c,d;
	cin>>d;
	for(i=2;i<=d;i++)
	{
		for(a=2;a<i;a++)
		{
			for(b=2;b<i;b++)
			{
				for(c=2;c<i;c++)
				{
					if(i*i*i==a*a*a+b*b*b+c*c*c)
					{
						if(a<=b&&b<=c)
						{
							printf("Cube = %d, Triple = (%d,%d,%d)\n",i,a,b,c);
						}
					}
				}
			}
		}
	}
    return 0;
}