class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (auto& it : tasks) {
            freq[it - 'A']++;
        }
        priority_queue<int> pq;
        for (auto& it : freq) {
            if (it > 0) {
                pq.push(it);
            }
        }
        int time=0;
        while(!pq.empty()){
            int cycle=n+1;
            vector<int>store;
            int taskcount=0;
            while(cycle-- && !pq.empty()){
                if(pq.top()>1){
                    store.push_back(pq.top()-1);
                }
                pq.pop();
                taskcount++;
            }
            for(auto &it:store){
                pq.push(it);
            }
            time+=pq.empty()?taskcount:n+1;
        }
        return time;
    }
};