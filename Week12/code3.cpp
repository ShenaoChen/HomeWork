class Solution {
public:
    int maxProduct(vector<string>& words) {
        int mark[1000]={0};
        int ans = 0;
        int length = words.size();

        for(int i = 0; i < length; i ++ )
            for(auto c : words[i])
                mark[i] |= 1 << (c - 'a');

        for(int i = 0; i < length; i ++ )
            for(int j = 0; j < length; j ++ )
                if((mark[i] & mark[j]) == 0)
                    ans = max(ans, int(words[i].size() * words[j].size()));
        
        return ans;
    }
};
