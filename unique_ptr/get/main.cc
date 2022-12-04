#include <cassert>
#include <iostream>
#include <memory>
#include <string>

/// get -> returns a pointer to the managed object

int main()
{
    auto uptrString = std::make_unique<std::string>("Hello, World!");
    assert(uptrString != nullptr);
    std::cout << *uptrString << std::endl;
    auto* pString = uptrString.get();
    *pString = "Hello, Universe!";
    std::cout << *uptrString << std::endl;
}
