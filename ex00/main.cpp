#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    std::cout << "=== Testing with std::vector ===" << std::endl;
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::cout << "Found: " << easyfind(vec, 3) << std::endl;
        std::cout << "Found: " << easyfind(vec, 1) << std::endl;
        std::cout << "Found: " << easyfind(vec, 5) << std::endl;

        std::cout << "Searching for non-existent value (42)..." << std::endl;
        easyfind(vec, 42);
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing with std::list ===" << std::endl;
    try {
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);

        std::cout << "Found: " << easyfind(lst, 20) << std::endl;
        std::cout << "Searching for non-existent value (99)..." << std::endl;
        easyfind(lst, 99);
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing with std::deque ===" << std::endl;
    try {
        std::deque<int> deq;
        deq.push_back(100);
        deq.push_back(200);
        deq.push_back(300);

        std::cout << "Found: " << easyfind(deq, 100) << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing with empty container ===" << std::endl;
    try {
        std::vector<int> empty;
        easyfind(empty, 1);
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
