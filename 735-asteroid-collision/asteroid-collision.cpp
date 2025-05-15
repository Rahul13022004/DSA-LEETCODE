class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       
        stack<int> st;
        for (auto it : asteroids) {
            if (it > 0)
                st.push(it);
            else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(it)) {
                    st.pop();
                }
                if (st.empty() || st.top() < 0) {
                    st.push(it);
                }
                if(!st.empty() && st.top()==abs(it)){
                    st.pop();
                }
            }
        }
         vector<int> ans(st.size());
        int i = st.size() - 1;
        while (!st.empty()) {
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};