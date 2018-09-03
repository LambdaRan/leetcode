
#include <iostream>
#include <vector>

using namespace std;

class Foo
{
public:
    Foo()
    {
        cout << "1" << endl;
    }
    Foo(const Foo& foo)
    {
        (void)foo;
        cout << " 2" << endl;
    }
    Foo(Foo&& foo)
    {
        (void)foo;
        cout << "3" << endl;
    }

    void* operator new(size_t s)
    {
        cout << "4" << endl;
        (void)s;
        return NULL;
    }
};
int main()
{
    vector<Foo> vf;
    vf.push_back(Foo());

    return 0;
}
