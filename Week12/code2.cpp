class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> hash;
        bool flag = true;
        int res = 0;
        long long sum = 0;
        int l = rectangles[0][0],r = rectangles[0][2],t = rectangles[0][3],b = rectangles[0][1];

        for(auto rectangle : rectangles){
            sum += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);

            l=min(l, rectangle[0]);
            r=max(r, rectangle[2]);
            t=max(t, rectangle[3]);
            b=min(b, rectangle[1]);

            hash[{rectangle[0], rectangle[1]}] ++;
            hash[{rectangle[0], rectangle[3]}] ++;
            hash[{rectangle[2], rectangle[1]}] ++;
            hash[{rectangle[2], rectangle[3]}] ++;
        }
        for(auto item : hash)
            if(item.second == 1) res ++;
            else if(item.second == 3) return false;

        if(hash[{l,b}] != 1) flag = false;
        if(hash[{l,t}] != 1) flag = false;
        if(hash[{r,b}] != 1) flag = false;
        if(hash[{r,t}] != 1) flag = false;
        if(sum != (long long)(r - l) * (t - b)) flag = false;

        if(res == 4 && flag) return true;
        else return false;
    }
};
