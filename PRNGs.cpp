#include <iostream>

uint LCG16()
{
    static uint s_state{ 5323 };

    // Generate the next number 
    //modify the state using large constants and intentionally make it hard to overflow
    s_state = s_state * 8253729 + 2396403; //first modify the state
    return s_state % 32768; //the new state to generate the next number 
}

int main()
{
    for (int i{1}; i <= 100; i++)
    {
        std::cout << LCG16() << "\n";

        if (i % 10 == 0)
        {
            std::cout << '\n';
        }
    }
}