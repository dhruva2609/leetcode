class Solution {
public:
    bool isPalindrome(int x) {
        int r;
        long long sum=0;
        if(x<0){
            return false;
        }
        int original =x;
        while(x!=0){
            r=x%10;
            sum=sum*10+r;
            x=x/10;
        }
        return (original==sum);
    }
};
