class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;


        while(left < right){

         char chl = s[left];
         char chr = s[right];

         if(isalnum(chl) != 0 && isalnum(chr) != 0){
            if(tolower(chl) != tolower(chr)) return false;
            left ++;
            right --;
         }else if(isalnum(chl) == 0) left ++;
         else if(isalnum(chr) == 0) right --;
         else{
            left ++;
            right --;
         }

        }

        return true;
    }
};