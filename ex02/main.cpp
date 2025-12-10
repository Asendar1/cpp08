#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "=== Test 1: MutantStack basic operations ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << "\nIterating through MutantStack:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    std::cout << "\n=== Test 2: Same test with std::list ===" << std::endl;
    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << "Back element: " << lst.back() << std::endl;

    lst.pop_back();

    std::cout << "Size after pop: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;

    std::cout << "\nIterating through std::list:" << std::endl;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << "\n=== Test 3: Copy constructor ===" << std::endl;
    MutantStack<int> mstack2(mstack);
    std::cout << "Copied stack size: " << mstack2.size() << std::endl;
    std::cout << "Copied stack top: " << mstack2.top() << std::endl;

    std::cout << "\n=== Test 4: Assignment operator ===" << std::endl;
    MutantStack<int> mstack3;
    mstack3.push(42);
    mstack3 = mstack;
    std::cout << "Assigned stack size: " << mstack3.size() << std::endl;
    std::cout << "Assigned stack top: " << mstack3.top() << std::endl;

    std::cout << "\n=== Test 5: String MutantStack ===" << std::endl;
    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("!");

    std::cout << "String stack iteration:" << std::endl;
    for (MutantStack<std::string>::iterator i = strStack.begin(); i != strStack.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;

    return 0;
}
