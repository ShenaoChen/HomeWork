class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> hash;
        for (char ch: s) 
            hash[ch] ++;

        vector<int> cnt(10);
        cnt[0] = hash['z'];
        cnt[2] = hash['w'];
        cnt[4] = hash['u'];
        cnt[6] = hash['x'];
        cnt[8] = hash['g'];

        cnt[3] = hash['h'] - cnt[8];
        cnt[5] = hash['f'] - cnt[4];
        cnt[7] = hash['s'] - cnt[6];

        cnt[1] = hash['o'] - cnt[0] - cnt[2] - cnt[4];

        cnt[9] = hash['i'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += char(i + '0');
            }
        }
        return ans;
    }
};
