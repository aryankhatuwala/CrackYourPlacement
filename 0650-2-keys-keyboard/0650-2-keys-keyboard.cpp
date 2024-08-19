class Solution {
public:
    int func(int lastCopy, int leng,int pasteEnable, int n)
    {
        if(leng == n) return 0;

        int copyPaste,paste;
        copyPaste=paste=INT_MAX/2;
        
        if(leng+leng<=n)
        copyPaste=2+func(leng,leng+leng,1,n); 

        if(pasteEnable==1 and leng+lastCopy<=n)
        paste=1+func(lastCopy, leng+lastCopy,1, n);

        return min(copyPaste,paste);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        return func(1,1,0,n);
    }
};