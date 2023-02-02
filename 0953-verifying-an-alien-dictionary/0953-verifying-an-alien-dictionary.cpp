class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26];
        for(int i=0;i<order.size();i++) mapping[order[i]-'a']=i;
        for(auto &word: words){
            for(int i=0;i<word.size();i++){
                word[i]=mapping[word[i]-'a'];
            }
                
        }
        return is_sorted(words.begin(),words.end());
    }
};

 // bool isAlienSorted(vector<string> words, string order) {
 //        int mapping[26];
 //        for (int i = 0; i < 26; i++)
 //            mapping[order[i] - 'a'] = i;
 //        for (string &w : words)
 //            for (char &c : w)
 //                c = mapping[c - 'a'];
 //        return is_sorted(words.begin(), words.end());
 //    }