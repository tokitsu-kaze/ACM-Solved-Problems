class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        for(auto it:nums)
        {
            if(it==target) return i;
            i++;
        }
        return -1;
    }
};
