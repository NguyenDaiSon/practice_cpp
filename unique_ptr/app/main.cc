#include <cassert>
#include <iostream>
#include <memory>

/// This program is to practice about std::unique_ptr
/// Reference:
/// [ 1 ] https://learn.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-unique-ptr-instances?view=msvc-170
///
/// std::unique_ptr
///  - A unique_ptr can only be moved.
///    This means that the ownership of the memory resource is transferred to another unique_ptr
//     and the original unique_ptr no longer owns it.
///  - Use the make_unique helper function to construct a unique_ptr
//
int main()
{
    auto uptrInt = std::make_unique<int>(10);
    assert(uptrInt != nullptr);
    std::cout << *uptrInt << std::endl;
}
