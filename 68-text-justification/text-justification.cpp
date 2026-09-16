class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> result;
         int i = 0;
        int n = words.size();
        
        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].length();
            
            // Find out how many words can fit greedily in the current line
            while (j < n && lineLength + 1 + words[j].length() <= maxWidth) {
                lineLength += 1 + words[j].length();
                j++;
            }
            
            int numWords = j - i;
            std::string line = "";
            
            // Case 1: The last line or a line with only one word (Left-Justified)
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                // Pad remaining spaces at the end
                line += std::string(maxWidth - line.length(), ' ');
            } 
            // Case 2: Fully justified line
            else {
                // Calculate total spaces to distribute
                int totalWordsLength = 0;
                for (int k = i; k < j; k++) {
                    totalWordsLength += words[k].length();
                }
                int totalSpaces = maxWidth - totalWordsLength;
                
                int baseSpaces = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);
                
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        // Distribute base spaces + 1 extra space if available
                        int spacesToGive = baseSpaces + (k - i < extraSpaces ? 1 : 0);
                        line += std::string(spacesToGive, ' ');
                    }
                }
            }
            
            result.push_back(line);
            i = j; // Move to the next set of words
        }
        
        return result;


    }
};