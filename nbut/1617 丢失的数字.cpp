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
    int n,m,a,count,i;
    map<int,int> map;
    while(cin>>n>>m)
    {
		count=0;
		map.clear();
        while(m--)
        {
			scanf("%d",&a);
			map[a]=1;
		}
		for(i=1;i<=n;i++)
		{
			if(!map[i]) count++;
		}
		cout<<count<<endl;
    }
    return 0;
}