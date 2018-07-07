
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

/*
* Name: 翻转单词顺序列
* Description: 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
* 同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
* 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
* 正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*
*/
class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty()) return str;
        std::stack<std::string> reverseWordStack;
        
        size_t slowIndex = 0;
        size_t fastIndex = 0;
        while (slowIndex <= fastIndex && fastIndex < str.size())
        {
            if (str[fastIndex] == ' ')
            {
                std::string words(std::next(str.begin(), slowIndex), std::next(str.begin(), fastIndex));
                reverseWordStack.push(words);
                reverseWordStack.push(std::string(" "));
                ++fastIndex;
                slowIndex = fastIndex;
            }
            else  
            {
                ++fastIndex;
            }
        }
        if (slowIndex < fastIndex && fastIndex == str.size())
        {
            std::string words(std::next(str.begin(), slowIndex), str.end());
            reverseWordStack.push(words);            
        }
        std::string result;
        while (!reverseWordStack.empty())
        {
            result += reverseWordStack.top();
            reverseWordStack.pop();
        }
        return result;
    }
    // 使用内存IO在牛客网不能使用（段错误）
    string ReverseSentence1(string str) {
        if (str.empty()) return str;
        std::stack<std::string> reverseWordStack;
        // 使用内存IO流处理 string
        std::istringstream allWords(str);
        std::string word;
        while (allWords >> word)
        {
            reverseWordStack.push(word);
            reverseWordStack.push(std::string(" "));
        }
        // 弹出栈顶多余的一个空格
        reverseWordStack.pop(); 
        std::ostringstream result;
        while (!reverseWordStack.empty())
        {
            result << reverseWordStack.top();
            reverseWordStack.pop();
        }
        return result.str();
    }
};

int main() 
{
    Solution s;

    string str = "student. a am I";

    std::cout << s.ReverseSentence(str);

    std::cout << std::endl;
    return 0;
}
