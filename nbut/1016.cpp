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
char a[1010][1010];
int main()
{
    int n,m,i,j,cnt;
    while(cin>>n>>m)
    {
		getchar();
        for(i=0;i<n;i++)
        {
            scanf("%s",a[i]);
        }
        cnt=0;
        for(i=0;i<n-5;i++)
        {
            for(j=0;j<m-5;j++)
            {
				if(a[i-1][j+1]!='*'&&a[i-1][j+2]!='*'&&a[i-1][j+3]!='*'&&a[i-1][j+4]!='*'&&a[i][j]!='*'&&a[i][j+1]=='*'&&a[i][j+2]=='*'&&a[i][j+3]=='*'&&a[i][j+4]=='*'&&a[i][j+5]!='*'&&a[i+1][j-1]!='*'&&a[i+1][j]=='*'&&a[i+1][j+1]=='*'&&a[i+1][j+2]=='*'&&a[i+1][j+3]=='*'&&a[i+1][j+4]=='*'&&a[i+1][j+5]=='*'&&a[i+1][j+6]!='*'&&a[i+2][j-1]!='*'&&a[i+2][j]=='*'&&a[i+2][j+1]=='*'&&a[i+2][j+2]=='*'&&a[i+2][j+3]=='*'&&a[i+2][j+4]=='*'&&a[i+2][j+5]=='*'&&a[i+2][j+6]!='*'&&a[i+3][j-1]!='*'&&a[i+3][j]=='*'&&a[i+3][j+1]=='*'&&a[i+3][j+2]=='*'&&a[i+3][j+3]=='*'&&a[i+3][j+4]=='*'&&a[i+3][j+5]=='*'&&a[i+3][j+6]!='*'&&a[i+4][j-1]!='*'&&a[i+4][j]=='*'&&a[i+4][j+1]=='*'&&a[i+4][j+2]=='*'&&a[i+4][j+3]=='*'&&a[i+4][j+4]=='*'&&a[i+4][j+5]=='*'&&a[i+4][j+6]!='*'&&a[i+5][j]!='*'&&a[i+5][j+1]=='*'&&a[i+5][j+2]=='*'&&a[i+5][j+3]=='*'&&a[i+5][j+4]=='*'&&a[i+5][j+5]!='*'&&a[i+6][j+1]!='*'&&a[i+6][j+2]!='*'&&a[i+6][j+3]!='*'&&a[i+6][j+4]!='*') cnt++;
			}
        }
        cout<<cnt<<endl;
    }

    return 0;
}