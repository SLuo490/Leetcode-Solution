class Solution {
public:
    int countGoodSubstrings(string s) {
        int size = s.size();
        int counter = 0;
        
        //hash map
        unordered_map<char, int> map;
        
        //store the first three character into map
        for (int i = 0; i < 3; i++)
        {
            map[s[i]]++;
        }
        
        //if there are 3 distinct character in map increment answer
        if (map.size() == 3)
        {
            counter++;
        }
        
        //loop through the rest of the string starting at index 3
        for (int i = 3; i < s.size(); i++)
        {
            //add the next character of the string to the map
            map[s[i]]++;
            
            //delete the first character of the map
            map[s[i-3]]--;
            
            //if frequence of character is 0, erase it from map
            if (map[s[i-3]]==0)
            {
                map.erase(s[i-3]);
            }
            
            //if there are 3 distinct character in map increment counter
            if (map.size() == 3)
            {
                counter++;
            }
        }

        return counter;
        
    }
};
