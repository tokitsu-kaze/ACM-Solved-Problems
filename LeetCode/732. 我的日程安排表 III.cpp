class MyCalendarThree {
public:
    map<int,int> mp;
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int now=0;
        int ans=0;
        for(auto it:mp)
        {
            now+=it.second;
            ans=max(ans,now);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
