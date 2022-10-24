class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>mp;
//         put all the characters of allowed string in to map
        for(auto it:allowed){
            mp[it]++;
        }
        int count=0;
        bool flag;
//         now we will check for all the word present in words
//         if all the character of word is present in map then increase the count;
         for(int i = 0; i < words.size(); i++) {     // iterating in words vector.
            flag = true;                            // setting flag to true for each word in the vector words.
            for(char c : words[i]) {                // checking each character of word.
                if(mp[c] == 0) {                    // if character is not present in the map, set flag to false and break the loop.
                    flag = false;
                    break;
                }
            }
            if(flag) {                              // if flag is true, that means all the character is from allowed string and the word is consistent.
                count++;
            }
        }
        
        return count;
    }
};