class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        int end = s.size()-1;
        while(end >= 0){
            while(end >= 0 && s[end] == ' ')
              end--;
              if(end < 0)
                break;
              string s1 = "";
              while(end >= 0 && s[end] != ' '){
                s1 = s[end] + s1;
                end--;
              }
              arr.push_back(s1);
        }

         if(arr.empty())           
            return "";
        string s2 = "";
        s2 = s2 + arr[0];
        for(int i = 1;i < arr.size();i++){
            s2 = s2 + " " + arr[i];
        }
        return s2;

    }
};