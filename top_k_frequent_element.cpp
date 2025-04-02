class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }

        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto& [num, freq] : mpp) {
            pq.push({freq, num});
            if (pq.size() > k) {
                pq.pop();  
            }
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; --i) {
            result[i] = pq.top().second;
            pq.pop();
        }

        return result;
    }
};
