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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
int main()
{
	int s,v1,v2,t1,t2,temp1,temp2;
	while(~scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2))
	{
		temp1=s*v1+2*t1;
		temp2=s*v2+2*t2;
	//	cout<<temp1<<" "<<temp2<<endl;
		if(temp1<temp2) puts("First");
		else if(temp1>temp2) puts("Second");
		else puts("Friendship");
	}
	return 0;
}