class Solution {
public:
    bool isPalindrome(int x) {
      if(x < 0)
        return false;
        long long int f;
        int y = x;
      while(y){
        int d = y%10;
        f = f*10+d;
         y = y/10;
      }  
      if(f == x)
      return true;
      else
      return false;
    }
};