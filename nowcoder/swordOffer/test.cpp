#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class C1 
{
public: 
    string GetName()
    {
        return "hello C1";
    }
};
class C2 
{
public: 
    string GetName()
    {
        return "hello" + mName;
    }
private: 
    string mName = "C2";
};

class C3 
{
public: 
    string GetName()
    {
        return "hello"+name;
    }
private: 
    static string name;
};
string C3::name = "C3";

class C4 
{
public: 
    virtual string GetName()
    {
        return "hello C4";
    }
};

int main()
{
    C1* pC1 = nullptr;
    C2* pC2 = nullptr;
    C3* pC3 = nullptr;
    C4* pC4 = nullptr;

    cout << pC1->GetName() << endl;
    //cout << pC2->GetName() << endl;
    cout << pC3->GetName() << endl;
    //cout << pC4->GetName() << endl;
    return 0;
}   
