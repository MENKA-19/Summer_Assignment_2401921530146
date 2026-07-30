class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> s1;
        set<string> re;

        if(s.size() < 10)
          return {};

        for(int i = 0;i <= s.size()-10;i++){


            string dna = s.substr(i,10);

            if(s1.contains(dna))
              re.insert(dna);

              s1.insert(dna);
        }

        vector<string> arr(re.begin(),re.end());


        return arr;
    }
};