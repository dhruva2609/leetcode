class Solution {
public:
    string toLower(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
        }
        return s;
    }
    bool isPalindrome(string s) {
        s=toLower(s);
        string temp;
        int i=0;
        int j=0;
        while(i<s.length()){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                temp+=s[i];
                j++;
            }
            i++;
        }
        int st=0;
        int e=temp.length()-1;
        while(st<=e){
            if(temp[st]==temp[e]){
                st++;
                e--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
