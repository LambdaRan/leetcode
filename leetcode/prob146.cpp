
// https://leetcode.com/problems/lru-cache/description/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;
/*
* Name: 
* Description: 
*
*/
struct node 
{
    node(int k, int v)
        : key_(k), value_(v), prev_(NULL), next_(NULL)
    {}
    int key_;
    int value_;
    struct node* prev_;
    struct node* next_;
};

class LRUCache {
public:
    LRUCache(int capacity) 
        : unmap_(), head_(capacity, 0)
    {
        head_.prev_ = NULL;
        head_.next_ = NULL;
    }
    
    int get(int key) {
        auto ret = unmap_.find(key);
        if (ret != unmap_.end())
        {
            int value = ret->second->value_;
            _updataNode(ret->second, value);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // 查看是不是现有的值
        auto ret = unmap_.find(key);
        if (ret != unmap_.end())
        {
            // 更新值
            _updataNode(ret->second, value);
        }
        else  
        {
            if (head_.value_ + 1 > head_.key_)
            {
                // 把最近最少使用的删除
                _removeOld();
            }
            // 添加新值到最前面
            node* newNode = new node(key, value);
            _addNode(newNode);
        }
    }
private:  
    void _addNode(node* newNode)
    {
        // 缓存是空
        if (head_.prev_ == NULL && head_.next_ == NULL)
        {
            head_.prev_ = newNode;
            head_.next_ = newNode;
            
            newNode->next_ = head_.prev_;
            newNode->prev_ = head_.next_;
        }
        else  
        {
            // 将新添加的节点使用头插法放在第一个
            newNode->next_ = head_.prev_;
            head_.prev_->prev_ = newNode;
            newNode->prev_ = head_.next_;
            head_.next_->next_ = newNode;
        }
        // 更新头部信息
        head_.prev_ = newNode;
        head_.value_ += 1;
        unmap_[newNode->key_] = newNode;
    }
    void _removeOld()
    {
        if (head_.prev_ != NULL && head_.next_ != NULL)
        {

            node* tail = head_.next_;
            if (head_.value_ == 1)
            {
                head_.prev_ = NULL;
                head_.next_ = NULL;
                head_.value_ = 0;
            }
            else  
            {
                head_.next_ = tail->prev_;
                head_.next_->next_ = head_.prev_;
                head_.prev_->prev_ = head_.next_;
                head_.value_ -= 1;
            }
            unmap_.erase(tail->key_);
            delete tail;
        }
    }
    void _updataNode(node* pnode, int value)
    {
        pnode->value_ = value;
        if (head_.next_->key_ == pnode->key_) return;
        node* prevNode = head_.next_->prev_;
        pnode->prev_->next_ = pnode->prev_;
        pnode->next_->prev_ = pnode->prev_;
        if (head_.next_->key_ == pnode->key_)
            head_.next_ = prevNode;
        pnode->next_ = head_.prev_;
        head_.prev_->prev_ = pnode;
        pnode->prev_ = head_.next_;
        head_.next_->next_ = pnode;
        head_.prev_ = pnode;

        // if (head_.next_->value_ == pnode->value_)
        // {
        //     node* prevNode = head_.next_->prev_;
        //     prevNode->next_ = head_.prev_;
        //     head_.prev_->prev_ = prevNode;
        //     head_.next_ = prevNode;
        // }
        // else
        // {
        //     node* prevNode = pnode->prev_;
        //     prevNode->next_ = pnode->next_;
        //     pnode->next_->prev_ = prevNode;
        // } 
        // // 移到头部
        // pnode->next_ = head_.prev_;
        // head_.prev_->prev_ = pnode;
        // pnode->prev_ = head_.next_;
        // head_.next_->next_ = pnode;
        // head_.prev_ = pnode;
    }
private: 
    unordered_map<int, node*> unmap_;
    node head_;
};
// class LRUCache 
// {
// private:  
//     typedef pair<int, int> Entry;
//     typedef list<Entry>::iterator ListIter;
//     list<Entry> list_;
//     unordered_map<int, ListIter> unMap_;
//     size_t allSize_;
// public:
//     LRUCache(int capacity)
//         : list_(), unMap_(), allSize_(capacity)
//     {}
    
//     int get(int key) 
//     {
//         auto ret = unMap_.find(key);
//         if (ret != unMap_.end())
//         {
//             Entry entry(*(ret->second));
//             list_.erase(ret->second);
//             list_.push_front(entry);
//             unMap_[entry.first] = list_.begin();
//             return entry.second;
//         }
//         return -1;
//     }
    
//     void put(int key, int value) 
//     {
//         Entry entry(key, value);
//         auto ret = unMap_.find(key);
//         // 存在值，则更新
//         if (ret != unMap_.end())
//         {
//             list_.erase(ret->second);
//         }
//         else  
//         {
//             if (list_.size()+1 > allSize_)
//             {
//                 ListIter oldEntryIter = prev(list_.end());
//                 unMap_.erase(oldEntryIter->first);
//                 list_.erase(oldEntryIter);
//             }
//         }
//         list_.push_front(entry);
//         unMap_[entry.first] = list_.begin();
//     }
// };

int main() 
{
    cout << "146" << endl;
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;      // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout << cache.get(1) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3
    cout << cache.get(4) << endl;       // returns 4
    std::cout << std::endl;
    return 0;
}

