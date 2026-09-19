class Solution {
public:
    int strStr(string haystack, string needle) {
        int s = needle.size();
        

        int j = -1;
        for(int i = 0;i<haystack.size();i++){
           string str = haystack.substr(i,s);
           if(str == needle){
              j = i;
              
              break;
           }

        }
    
         return j;

    }
};