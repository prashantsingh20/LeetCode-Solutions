/* 28. Implement strStr()
https://leetcode.com/problems/implement-strstr/
*/
class Solution {
 public:
     static int strStr(const std::string& haystack, const std::string& needle)
     {
         if (needle.empty())
         {
             return 0;
         }

         if (haystack.empty())
         {
             return -1;
         }

         if (haystack == needle)
         {
             return 0;
         }
         int firstIndex = -1;
         const std::string::size_type patternSize = needle.size(); 
         std::string temp;
         for (size_t i = 0; i < haystack.size(); ++i)
         {
            if (temp.size() == patternSize)
            {
                temp.erase(temp.begin());
            }
            temp += haystack[i];
            if (temp == needle)
            {
                firstIndex = (i+1) - needle.size();
                break;
            }
         }

         return firstIndex;
     }
 };