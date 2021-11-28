class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        if(s != goal){
            vector<int> tmp;
            for(int i = 0; i < s.size(); i ++ )
                if(s[i] != goal[i])
                    tmp.push_back(i);
            if(tmp.size() != 2 || s[tmp[0]] != goal[tmp[1]] || s[tmp[1]] != goal[tmp[0]])
                return false;
            else
                return true;
        }
        int a[26] = {0};
        for(int i = 0; i < s.size(); i ++ ){
            a[s[i] - 'a'] ++;
            if(a[s[i] - 'a'] >= 2)
                return true;
        }
        return false;
    }
};
