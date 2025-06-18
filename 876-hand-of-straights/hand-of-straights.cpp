class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        while (!freq.empty()) {
            int start = freq.begin()->first;

            // Try to build a group starting from 'start'
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;

                if (freq[card] == 0) return false;
                freq[card]--;

                if (freq[card] == 0) {
                    freq.erase(card);
                }
            }
        }

        return true;
    }
};
