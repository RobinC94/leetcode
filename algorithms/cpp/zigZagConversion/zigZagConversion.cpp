// Source : https://oj.leetcode.com/problems/zigzag-conversion/
// Author : Robin Chen
// Date   : 2018.3.26

/********************************************************************************** 
* 
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
* (you may want to display this pattern in a fixed font for better legibility)
* 
* P   A   H   N
* A P L S I I G
* Y   I   R
* 
* And then read line by line: "PAHNAPLSIIGYIR"
* 
* Write the code that will take a string and make this conversion given a number of rows:
* 
* string convert(string text, int nRows);
* 
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
* 
*               
**********************************************************************************/

// 思路1：创建两个迭代器
// 一个迭代s的各位
// 另一个Z形迭代
// 这么做的缺点是需要n个string来保存中间结果

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> line(numRows);
        string res;
        int len = s.length();
        bool down = true;
        
        int index = 0;
        for(int i = 0; i < len; i++){
            line[index]+=s[i];
            if(down) index++;
            else index--;
            if (index==0) down = true;
            if(index == numRows-1) down = false;
        }
        
        for(int i = 0; i < numRows; i++){
            res = res + line[i];
        }
        
        return res;
    }
};

// 运行结果：
// Accepted	49ms	15.49%
// emmmm 果然不够好

/**********************************************************************************/

// 思路2：
// 更省空间的做法是直接建立两个迭代器之间的映射
// 也就是直接换位就好了
// 简单写一下就会发现是模2(n-1)

// 然后写了一下发现，从结果到输入的映射更简单
// 实际上就是每行递增，到下一行的时候以行号作为初始
// 而行内的增量是有规律的，首末两行为行的长度
// 其余行为周期2的波动

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;

        int strLen = s.length();
        string res(strLen,'0'); 
        
        int index = 0, currentLine = 0, offset = 0, pos = 0;
        for (int i = 0; i < strLen; ++i){
            if (currentLine == 0 || currentLine == numRows - 1)
                offset = (numRows-1)*2;
            else offset = (numRows - 1 - currentLine) * 2;
            
            res[i] = s[index];
            if (currentLine != 0 && currentLine != numRows - 1 && pos%2==1)
                 index += (numRows-1)*2 - offset;
            
            else
                index+= offset;
            pos++;
            if (index > strLen - 1){
                currentLine++;
                index = currentLine;
                pos = 0;
            }              
        }
  
        return res;
    }
};

// 运行结果：
// Accepted	37ms	36.90%
// 这下至少可以说服自己了
