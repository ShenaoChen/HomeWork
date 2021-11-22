//方法一
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0, length = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0, j = 0; i < length; i ++ ){
            while(nums[i] - nums[j] > 1) j ++;
            if(nums[i] - nums[j] == 1)
                ans = max(ans, i - j + 1);
        }
        return ans;
    }
};

//方法二
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> hash;
        for(auto num : nums) hash[num] ++;
        for(auto c : hash){
            if(hash.count(c.first + 1))
                ans = max(ans, c.second + hash[c.first + 1]);
        }
        return ans;
    }
};
