const int MAX=1000+10;
struct Manacher
{
	int p[MAX];
	string work(char *s)//return max length of palindrome
	{
		int r,mid,i,len,res=0;
		len=strlen(s+1);
		//odd
		r=mid=0;
        memset(p,0,sizeof(p));
        int rr;
		for(i=1;i<=len;i++)
		{
			//palindrome substring s[i,i]
			if(r>i) p[i]=min(p[2*mid-i],r-i);
			while(i+p[i]+1<=len&&s[i+p[i]+1]==s[i-p[i]-1])
			{
				//palindrome substring s[i-p[i]-1,i+p[i]+1]
				p[i]++;
			}
			if(i+p[i]>r)
			{
				r=i+p[i];
				mid=i;
			}
			res=max(res,p[i]*2+1);
            if(p[i]*2+1==res) rr=r;
		}
		//even
		r=mid=0;
		memset(p,0,sizeof(p));
		for(i=2;i<=len;i++)
		{
			if(r>i) p[i]=min(p[2*mid-i],r-i+1);
			while(i+p[i]<=len&&s[i+p[i]]==s[i-p[i]-1])
			{
				//palindrome substring s[i-p[i]-1,i+p[i]]
				p[i]++;
			}
			if(i+p[i]-1>r)
			{
				r=i+p[i]-1;
				mid=i;
			}
			res=max(res,p[i]*2);
            if(p[i]*2==res) rr=r;
		}
        string ans="";
        for(i=rr;i>=rr-res+1;i--) ans+=s[i];
        reverse(ans.begin(),ans.end());
		return ans;
	}
}la;

class Solution {
public:
    string longestPalindrome(string s) {
        string tmp=" "+s;
        return la.work((char *)(tmp.c_str()));
    }
};
