class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int cnt1[26] = {0};
        int cnt2[26] = {0};
        int slen = s.size(), plen = p.size();
        for(int i = 0; i < plen; i ++){
            if(i >= slen)
                return res;
            cnt1[s[i] - 'a'] ++;
            cnt2[p[i] - 'a'] ++;
        }
        for(int i = 0, j = plen - 1; j < slen; i ++, j ++){
            bool flag = true;
            for(int k = 0; k < 26; k ++)
                if(cnt1[k] != cnt2[k]){
                    flag = false;
                    break;
                }
            if(flag) res.push_back(i);
            cnt1[s[i] - 'a'] --;
            if(j != slen - 1)
                cnt1[s[j + 1] - 'a'] ++;
        }
        return res;
    }
};
