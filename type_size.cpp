#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#include <bitset>

int main() {

    std::cout << "string: " << sizeof(std::string) << std::endl;

    std::cout << std::endl;
    std::cout << "vector<int>: " << sizeof(std::vector<int>) << std::endl;
    std::cout << "vector<char>: " << sizeof(std::vector<char>) << std::endl;
    std::cout << "vector<std::string>: " << sizeof(std::vector<std::string>) << std::endl;
    std::cout << "vector<bool>: " << sizeof(std::vector<bool>) << std::endl;

    std::cout << std::endl;
    std::cout << "array<int, 2>: " << sizeof(std::array<int, 2>) << std::endl;
    std::cout << "array<char, 2>: " << sizeof(std::array<char, 2>) << std::endl;

    std::cout << std::endl;
    std::cout << "list<int>: " << sizeof(std::list<int>) << std::endl;
    std::cout << "list<char>: " << sizeof(std::list<char>) << std::endl;
    std::cout << "forward_list<int>: " << sizeof(std::forward_list<int>) << std::endl;
    std::cout << "forward_list<char>: " << sizeof(std::forward_list<char>) << std::endl;

    std::cout << std::endl;
    std::cout << "deque<int>: " << sizeof(std::deque<int>) << std::endl;

    std::cout << std::endl;
    std::cout << "map<int, int>: " << sizeof(std::map<int, int>) << std::endl;
    std::cout << "map<char, char>: " << sizeof(std::map<char, char>) << std::endl;
    std::cout << "multimap<int, int>: " << sizeof(std::multimap<int, int>) << std::endl;
    std::cout << "unordered_map<int, int>: " << sizeof(std::unordered_map<int, int>) << std::endl;
    std::cout << "unordered_multimap<int, int>: " << sizeof(std::unordered_multimap<int, int>) << std::endl;

    std::cout << std::endl;
    std::cout << "set<int>: " << sizeof(std::set<int>) << std::endl;
    std::cout << "set<char>: " << sizeof(std::set<char>) << std::endl;
    std::cout << "multiset<int>: " << sizeof(std::multiset<int>) << std::endl;
    std::cout << "unordered_set<int>: " << sizeof(std::unordered_set<int>) << std::endl;
    std::cout << "unordered_multiset<int>: " << sizeof(std::unordered_multiset<int>) << std::endl;

    std::cout << std::endl;
    std::cout << "bitset<1>: " << sizeof(std::bitset<1>) << std::endl;
    std::cout << "bitset<32>: " << sizeof(std::bitset<32>) << std::endl;
    std::cout << "bitset<64>: " << sizeof(std::bitset<64>) << std::endl;
    std::cout << "bitset<65>: " << sizeof(std::bitset<65>) << std::endl;
    std::cout << "bitset<128>: " << sizeof(std::bitset<128>) << std::endl;
    std::cout << "bitset<129>: " << sizeof(std::bitset<129>) << std::endl;
}

// results:

// string: 32

// vector<int>: 24
// vector<char>: 24
// vector<std::string>: 24
// vector<int>(2): 24
// vector<bool>: 40

// array<int, 2>: 8
// array<char, 2>: 2

// list<int>: 24
// list<char>: 24
// forward_list<int>: 8
// forward_list<char>: 8

// deque<int>: 80

// map<int, int>: 48
// map<char, char>: 48
// multimap<int, int>: 48
// unordered_map<int, int>: 56
// unordered_multimap<int, int>: 56

// set<int>: 48
// set<char>: 48
// multiset<int>: 48
// unordered_set<int>: 56
// unordered_multiset<int>: 56

// bitset<1>: 8
// bitset<2>: 8
// bitset<10>: 8
// bitset<32>: 8
// bitset<64>: 8
// bitset<65>: 16
// bitset<128>: 16
// bitset<129>: 24