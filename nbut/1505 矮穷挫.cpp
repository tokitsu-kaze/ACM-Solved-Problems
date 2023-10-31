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
    char a[21];
    char *end;
    while(cin>>a)
    {
        cout<<strtol(a,&end,2)<<endl;
    }
    return 0;
}