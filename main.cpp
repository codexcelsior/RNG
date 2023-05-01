#include <iostream>



int plusOne()
{
    static int s_state {3};

    ++s_state;
    return s_state;
 
}

int main()
{
    std::cout << plusOne() << '\n';
    std::cout << plusOne() << '\n';
    std::cout << plusOne() << '\n';

}