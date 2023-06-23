class Solution {
public:
    string freqAlphabets(string s) {
		for(int i=26;i>=1;i--)
		{
			string tmp=to_string(i);
			if(i>=10) tmp+="#";
			string now;
			now+='a'+i-1;
			while(s.find(tmp)!=s.npos)
			{
				s.replace(s.find(tmp),(int)tmp.size(),now);
			}
		}
		return s;
    }
};
