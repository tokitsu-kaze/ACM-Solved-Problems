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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
int main()
{ 
	int i,a,b,cnt,max,t;
	while(cin>>a>>b)
	{
		max=0;
		printf("%d %d ",a,b);
		if(a>b) swap(a,b);
		for(i=a;i<=b;i++)
		{
			cnt=1;
			t=i;
			while(t!=1)
			{
				if(t%2) t=t*3+1;
				else t/=2;
				cnt++;
			}
			if(cnt>max) max=cnt;
		}
		cout<<max<<endl;
	}
    return 0;
}