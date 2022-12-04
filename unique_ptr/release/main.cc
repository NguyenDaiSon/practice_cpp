#include <cassert>
#include <iostream>
#include <memory>
#include <string>

/// release -> returns a pointer to the managed object and releases the ownership

int main(int argc, char* argv[])
{
    auto uptrString = std::make_unique<std::string>(argv[0]);
    assert(uptrString != nullptr);
    std::cout << "Program name is: " << *uptrString << std::endl;
    auto* pString = uptrString.release();
    // DANGEROUS
    // std::cout << *uptrString << std::endl;
    assert(uptrString.get() == nullptr);
    assert(*pString == std::string(argv[0]));
    delete pString;
}
