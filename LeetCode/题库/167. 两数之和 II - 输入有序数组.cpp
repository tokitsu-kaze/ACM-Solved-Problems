#define sz(x) (int)x.size()
typedef vector<int> VI;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		for(int i=0,j;i<sz(numbers);i++)
		{
			j=lower_bound(numbers.begin()+i+1,numbers.end(),target-numbers[i])-numbers.begin();
			if(j<sz(numbers) && numbers[i]+numbers[j]==target) return VI{i+1,j+1};
		}
		return VI{};
    }
};
