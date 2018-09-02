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
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-5;
const int MAX=1000000+10;
const ll mod=1e6;
int main()
{
	int n,i,cnt;
	while(~scanf("%d",&n))
	{
		cnt=0;
		for(i=0;i<=sqrt(n);i++)
		{
			int temp1=n-i*i,temp2=(int)(sqrt(temp1));
			if(temp2*temp2==temp1) cnt++;
		}
		printf("%d\n",cnt);
	} 
	return 0;
}