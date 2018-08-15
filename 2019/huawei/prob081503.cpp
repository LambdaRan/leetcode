
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <iterator>
#include <ctype.h>

using namespace std;

int calculation(int a, int b, char op)
{
    switch(op)
    {
        case '^':
            return a+1;
        case '+':
            return a + b;
        case '*':
            return a * b;
        default: return -1;
    }
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        std::vector<char> opera;
        std::vector<int> value;
        bool isComplete = false;
        for (size_t i = 0; i < line.size(); ++i)
        {
            if (isdigit(line[i]))
            {
                size_t s = i;
                for (; i < line.size(); ++i)
                {
                    if (!isdigit(line[i]))
                        break;
                }
                int val = stoi(line.substr(s, i-s));
                value.push_back(val);
                //cout << "find a number:" << val << endl;
                --i;
            }
            else  
            {
                switch (line[i])
                {
                    case '(':
                            if (!(line[i+1] == '^' || line[i+1] == '*' || line[i+1] == '+'))
                            {
                                //cout << "0" << line[i+1] << " ";
                                cout << -1 << endl;
                                return 0;
                            }
                            if (isComplete)
                            {
                                opera.clear();
                                value.clear();
                            }
                            opera.push_back(line[i]);
                        break;
                    case '^':
                    case '+':
                    case '*':
                        {
                            opera.push_back(line[i]);
                        }
                        break;
                    case ')':
                        {
                            // cout << "opera: ";
                            // std::copy(opera.begin(), opera.end(), std::ostream_iterator<char>(std::cout, " "));
                            // cout << endl;
                            // cout << "value: ";
                            // std::copy(value.begin(), value.end(), std::ostream_iterator<int>(std::cout, " "));
                            // cout << endl;

                            char op;
                            if (!opera.empty())
                            {
                                op = opera.back();
                                opera.pop_back();
                            }
                            else  
                            {
                                //cout << "1";
                                cout << -1 << endl;
                                return 0; 
                            }

                            if (!opera.empty() && opera.back() == '(')
                            {
                                opera.pop_back(); // 弹出左括号
                            }
                            else 
                            {
                                //cout << "2";
                                cout << -1 << endl;
                                return 0;  
                            }

                            int ret = 0;
                            int v1 = 0;
                            int v2 = 0;
                            if (op == '^')
                            {
                                if (!value.empty())
                                {
                                    v1 = value.back();
                                    value.pop_back();
                                }
                                else 
                                {
                                    //cout << "3";
                                    cout << -1 << endl;
                                    return 0;  
                                } 
                                ret = calculation(v1, 0, op);
                            }
                            else  
                            {
                                if (!value.empty())
                                {
                                    v1 = value.back();
                                    value.pop_back();
                                }
                                else 
                                {
                                    //cout << "4";
                                    cout << -1 << endl;
                                    return 0;  
                                }

                                if (!value.empty())
                                {
                                    v2 = value.back();
                                    value.pop_back();
                                }
                                else 
                                {
                                    //cout << "5";
                                    cout << -1 << endl;
                                    return 0;  
                                }
                                ret = calculation(v1, v2, op);
                            }
                            value.push_back(ret);
                            if (opera.empty())
                                isComplete = true;

                            // cout << "opera: ";
                            // std::copy(opera.begin(), opera.end(), std::ostream_iterator<char>(std::cout, " "));
                            // cout << endl;
                            // cout << "value: ";
                            // std::copy(value.begin(), value.end(), std::ostream_iterator<int>(std::cout, " "));
                            // cout << endl;
                        }
                        break;
                    default: 
                    break; 
                }
            }
        }
        cout << value.back() << endl;
    }
    return 0;
}
// (+ (* 2 3) (^ 4))()
// 11

// (+ (* 12 3) (^ 4))(* 2 3)
// 6

// (+ (* 12 3) (^ 4))
// 41
