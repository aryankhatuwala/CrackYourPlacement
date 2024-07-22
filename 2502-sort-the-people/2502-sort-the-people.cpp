class Solution {
public:
   struct State{
    int height; string name; int ind;
   };
   bool static cmp(State &a, State &b)
   {
    return a.height>b.height;
   }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string>ans;
        vector<State>temp;
        int n=names.size();
        for(int i=0;i<n;i++)
        {
          temp.push_back({heights[i],names[i],i});
        }
        sort(temp.begin(),temp.end(),cmp);
        for(auto it: temp)
        {
            ans.push_back(it.name);
        }
        return ans;
    }
};