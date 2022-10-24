class Solution {
public:
    int countPoints(string rings) {
//         if rings size is less than six then it's not possible bcz min cond is R1B1G1 whose length is 6
        if(rings.size() <  6)
            return 0;
        unordered_map<char,set<char>> s;
//         set will store all the colors on that rod
        for(int i = rings.size()-1;i>0;i-=2) 
           s[rings[i]].insert(rings[i-1]);
        int count = 0;
//         if any rod contains all the three colors then the set size w.r.t that is 3
        for(auto x : s)
            if(x.second.size() == 3)
                count++;
        return count;

    }
};

