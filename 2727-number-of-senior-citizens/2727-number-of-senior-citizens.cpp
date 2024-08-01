class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size(), count=0;
        for(int i=0;i<n;i++)
        {
            string str=details[i];
            string age=str.substr(11,2);
            if(stoi(age)>60) count++;
            // if(age>"60") count++;
        }
        return count;
    }
};