#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <list> 
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
#define pi acos(-1.0) 
using namespace std;
typedef long long ll;
int main()
{
	int a,b;
    while(~scanf("%d%d",&a,&b))
    {
		printf("%d\n",a%b);
	}
    return 0;
}