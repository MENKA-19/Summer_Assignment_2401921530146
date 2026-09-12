class Solution {
public:
    string minWindow(string s, string t) {
        
    
    
    
        if(s.length() < t.length()) 
           return "";

    
        vector<int> count_t(128, 0);
        vector<int> window(128, 0);

        
        int need = 0;
        for (char c : t) {
            if (count_t[c] == 0) need++;
            count_t[c]++;
        }

        int have = 0;
        int min_len = INT_MAX;
        int start_idx = -1;
        int l = 0;

        
        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            
            if (count_t[c] > 0 && window[c] == count_t[c]) {
                have++;
            }
            while (have == need) {
                
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start_idx = l;
                }

                char left_char = s[l];
                window[left_char]--;

                
                if (count_t[left_char] > 0 && window[left_char] < count_t[left_char]) {
                    have--;
                }
                
                l++; 
            }
        }

        
        return start_idx == -1 ? "" : s.substr(start_idx, min_len);
    }


};