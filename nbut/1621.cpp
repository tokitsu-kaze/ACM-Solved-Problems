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
using namespace std;
int main()
{
    int t,a,b;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>a>>b;
            if(a==0||b==0) puts("First");
            else if(a==1&&b==1) puts("Second");
            else
            {
                if((a+b-2)%2) puts("First");
                else puts("Second");
            }
        }
    }
    return 0;
}