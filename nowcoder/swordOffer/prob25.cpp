
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

/*
* Name: 复杂链表的复制
* Description: 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
* 另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
* （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*
* 
*/

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) 
        : label(x), next(NULL), random(NULL) 
    {}
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL) return NULL;

        // 存储 <旧节点， 克隆节点>
        map<RandomListNode*, RandomListNode*> oldNewMap;
        RandomListNode* oldCur = pHead->next;
        RandomListNode* newRoot = new RandomListNode(pHead->label);
        RandomListNode* newCur = newRoot;
        oldNewMap[pHead] = newRoot;
        while (oldCur)
        {
            newCur->next = new RandomListNode(oldCur->label);
            newCur = newCur->next;
            oldNewMap[oldCur] = newCur;
            oldCur = oldCur->next;
        }
        oldCur = pHead;
        newCur = newRoot;
        while (oldCur)
        {
            newCur->random = oldNewMap[oldCur->random];
            newCur = newCur->next;
            oldCur = oldCur->next;
        }
        return newRoot;
    }

//     1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
//     2、遍历链表，A1->random = A->random->next;
//     3、将链表拆分成原链表和复制后的链表    
    RandomListNode* Clone1(RandomListNode* pHead)
    {
        if(!pHead) return NULL;

        RandomListNode *currNode = pHead;
        while (currNode)
        {
            RandomListNode *node = new RandomListNode(currNode->label);
            node->next = currNode->next;
            currNode->next = node;
            currNode = node->next;
        }
        currNode = pHead;
        while (currNode)
        {
            RandomListNode *node = currNode->next;
            if (currNode->random)
            {
                node->random = currNode->random->next;
            }
            currNode = node->next;
        }
        //拆分
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *tmp;
        currNode = pHead;
        while (currNode->next)
        {
            tmp = currNode->next;
            currNode->next =tmp->next;
            currNode = tmp;
        }
        return pCloneHead;
    }
};

int main() 
{
    Solution s;

    std::cout << "method 1: \n";

    std::cout << std::endl;
    return 0;
}
