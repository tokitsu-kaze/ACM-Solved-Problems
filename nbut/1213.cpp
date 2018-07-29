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
    double a;
    while(cin>>a)
    {
		if(a<0) a=-a; 
        printf("%.6lf\n",a-(int)a);
    }
    return 0;
}