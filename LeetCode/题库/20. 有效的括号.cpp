class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for(auto it:s)
        {
            if(it=='(' || it=='{' || it=='[') stk.push_back(it);
            else
            {
                if(stk.empty()) return false;
                switch(stk.back())
                {
                    case '{':
                        if(it!='}') return false;
                        else break;
                    case '(':
                        if(it!=')') return false;
                        else break;
                    case '[':
                        if(it!=']') return false;
                        else break;
                }
                stk.pop_back();
            }
        }
        if(!stk.empty()) return false;
        return true;
    }
};
