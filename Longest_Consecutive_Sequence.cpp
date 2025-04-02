class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        vector<int>ans(st.size());
        auto it=st.begin();
        for(int i=0;i<st.size();i++){
           ans[i]=*next(st.begin(), i);
        }
        
        int count=0;
        int anss=0;
        for(int i=0;i<st.size()-1;i++){
          if(ans[i]==ans[i+1]-1){
            count++;
          }
          else{
            if(anss<count){
            anss=count;
            }
            count=0;
          }
        }
        return anss+1;
    }
};
