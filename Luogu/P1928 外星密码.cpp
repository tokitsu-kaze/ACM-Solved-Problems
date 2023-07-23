#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	vector<string> st;
	vector<int> st2;
	int now,ok;
	st.push_back("");
	string tmp="";
	ok=0;
	now=0;
	for(auto &it:s)
	{
		if(it>='0'&&it<='9')
		{
			now=now*10+it-'0';
			if(!ok)
			{
				st.push_back("");
				ok=1;
			}
		}
		else if(it=='[')
		{
			if(now) st2.push_back(now);
			now=0;
			ok=0;
		}
		else if(it==']')
		{
			if(now) st2.push_back(now);
			ok=0;
			tmp=st.back();
			now=st2.back();
			st.pop_back();
			st2.pop_back();
			while(now>0)
			{
				now--;
				st.back()+=tmp;
			}
			now=0;
		}
		else
		{
			st.back()+=it;
			ok=0;
		}
	}
	string res;
	for(auto &it:st) res+=it;
	cout<<res<<"\n";
	return 0;
}

