#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int ask(string s)
{
	cout<<"? "<<s<<endl;
	int res;
	cin>>res;
	return res;
}
int main()
{
	int T,n,i,f;
	cin>>T;
	while(T--)
	{
		cin>>n;
		string now;
		f=0;
		for(i=0;i<n;i++)
		{
			if(f==0) now+="0";
			else now="0"+now;
			if(!ask(now))
			{
				if(f==0) now[i]='1';
				else now[0]='1';
				if(f==0 && !ask(now))
				{
					f^=1;
					now.pop_back();
					i--;
				}
			}
		}
		cout<<"! "<<now<<endl;
	}
	return 0;
}
