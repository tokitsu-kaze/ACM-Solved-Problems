#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int main()
{
    int t,n,cnt;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n;
            cnt=0;
            while(n)
            {
                n>>=1;
                cnt+=n;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}
 