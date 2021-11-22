class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0;
        queue<pair<long long, int>> q;
        q.push({n, 0});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            //cout<<t.first<<endl;
            if(t.first == 1){
                ans = t.second;
                break;
            }
            if(t.first & 1){
                q.push({t.first + 1, t.second + 1});
                q.push({t.first - 1, t.second + 1});
            }
            else
                q.push({t.first / 2, t.second + 1});
        }
        return ans;
    }
};
