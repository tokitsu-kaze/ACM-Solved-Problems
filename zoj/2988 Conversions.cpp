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
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{
    int n,i;
    double a;
    char b[11];
	cin>>n;
    for(i=1;i<=n;i++)
    {
		cin>>a>>b;
		if(b[0]=='k') printf("%d %.4lf lb\n",i,2.2046*a);
		else if(b[0]=='l'&&b[1]=='b') printf("%d %.4lf kg\n",i,0.4536*a);
		else if(b[0]=='l') printf("%d %.4lf g\n",i,0.2642*a);
		else if(b[0]=='g') printf("%d %.4lf l\n",i,3.7854*a);
    }
    return 0;
}