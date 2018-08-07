#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

// 不能被继承的类
// 方法一：利用虚拟继承
// 方法二：C++11新标准提供的方法 在类名后面跟一个final
// class Base final {}; // Base 不能作为基类
template<typename T>
class MakeSealed
{
friend T;
private:
    MakeSealed() {}
    ~MakeSealed() {}
};

class SealedClass2 : virtual public MakeSealed<SealedClass2>
{
public: 
    SealedClass2() {}
    ~SealedClass2() {}
};
class Tr : public SealedClass2
{
public:
    Tr() {}
    ~Tr() {}
};
int main()
{
    SealedClass2 sealed2;
    return 0;
}


// bool isSameTree(TreeNode *p, TreeNode *q) 
// {
//     if(p == nullptr && q == nullptr) 
//         return true;
//     else if(p == nullptr || q == nullptr)
//     {
//         return false;
//     }
//     else if(p->val == q->val)
//     {
//         if(isSameTree(p->left,q->left) && isSameTree(p->right,q->right))
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     else
//     {
//         return false;
//     }
// }