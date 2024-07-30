class Solution {
    public:
        int minimumDeletions(string s) {
            int rightA = 0;
            int leftB = 0;

            for (int i=0; i<s.length(); i++){
                if (s[i] == 'a')
                    rightA += 1;
            }

            int deleteCount = leftB + rightA;

            for (int i=0; i<s.length(); i++)
            {
                if (s[i] == 'a') 
                    rightA -= 1;
                else 
                    leftB += 1;
                
                deleteCount = min(deleteCount, leftB + rightA);
            }
            return deleteCount;
        }
};