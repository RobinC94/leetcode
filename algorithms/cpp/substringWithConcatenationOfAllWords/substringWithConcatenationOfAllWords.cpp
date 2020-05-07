// https://leetcode.com/problems/substring-with-concatenation-of-all-words
// Author : Robin Chen
// Date   : 2020.05.06

/********************************************************************************** 
* 
* You are given a string, s, and a list of words, words, that are all of the same length. 
* Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
*
* Example 1:
* Input:
*   s = "barfoothefoobarman",
*   words = ["foo","bar"]
* Output: [0,9]
* Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
* The output order does not matter, returning [9,0] is fine too.
*
* Example 2:
* Input:
*   s = "wordgoodgoodgoodbestword",
*   words = ["word","good","best","word"]
* Output: []
*               
**********************************************************************************/

// 思路 1
// 先暴力破解+踩踩坑
// 三层循环
// 坑主要在给空的或者不够的输入、重复 word 以及正确结果出现在尾端

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordNum = words.size();
        int sLen = s.size();
        if (wordNum == 0 || sLen == 0)
            return res;
        int wordLen = words[0].size();
        if (sLen < wordLen * wordNum)
            return res;
        size_t i, j, k;
        for (i = 0; i <= sLen - wordLen * wordNum; ++i){
            vector<int> visited(wordNum);
            for (j = 0; j < wordNum; ++j){
                string subStr = s.substr(i + j * wordLen, wordLen);
                bool find = false;
                for(k = 0; k < wordNum; ++k){
                    if (subStr == words[k]){
                        if (visited[k] == 0){
                            visited[k] = 1;
                            find = true;
                            break;
                        }
                    }
                }
                if (!find){
                    break;
                }
            }
            if(j == wordNum)
                res.push_back(i);
        }
        return res;
    }
};

// Status: Time Limit Exceeded

/*********************************************************************************/

// 进入正题
// 思路 2
// 按照单词长度为步长搜索
// 也就是说单词长度为多少，就搜索多少轮
// 每一轮搜索中维护一个字典，统计新进来单词的数量，当达到目标长度时比较两个字典，当超过目标长度时去掉最早的单词
// 如果有不认识的单词直接清空

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordNum = words.size();
        int sLen = s.size();
        if (wordNum == 0 || sLen == 0)
            return res;
        int wordLen = words[0].size();
        if (sLen < wordLen * wordNum)
            return res;
        
        unordered_map <string, int> wordsMap;
        for (auto &i : words){
            wordsMap[i]++;
        }
        for (size_t startIdx = 0; startIdx < wordLen; ++startIdx){
            int curIdx, curLen = 0;
            unordered_map <string, int> curMap;
            for (curIdx=startIdx; curIdx<=sLen-wordLen; curIdx+=wordLen){
                string subStr = s.substr(curIdx, wordLen);
                if (wordsMap.find(subStr) != wordsMap.end()){
                    curMap[subStr]++;
                    curLen++;
                }
                else{
                    curMap.clear();
                    curLen = 0;
                }
                if (curLen == wordNum){
                    curLen--;
                    if (equalMap(curMap, wordsMap))
                        res.push_back(curIdx-curLen*wordLen);
                    subStr = s.substr(curIdx-curLen*wordLen, wordLen);
                    curMap[subStr]--;
                }
            }
        } 
        return res;
    }
    
    bool equalMap(unordered_map<string, int> &mapA, unordered_map<string, int> &mapB){
        if (mapA.size() != mapB.size())
            return false;
        unordered_map<string, int>::iterator iter;
        for(iter=mapA.begin(); iter!=mapA.end(); iter++)
            if(mapB.count(iter->first)==0||mapB[iter->first]!=iter->second)
                return false;
        return true;
    }
};

// Success
// Runtime: 48 ms, faster than 91.09% of C++ online submissions for Substring with Concatenation of All Words.
// Memory Usage: 16.7 MB, less than 73.91% of C++ online submissions for Substring with Concatenation of All Words.