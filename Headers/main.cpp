#include <iostream>
#include <random>
#include "Random.h"

int main()
{
    //Use Random::get()
    std::cout << Random::get(1, 6);

    //Create a reuseable random number generator that generates uniform numbers 
    //from 1 to 6

    std::uniform_int_distribution<> die6(1 , 6);

    // Print a bunch of random numbers
	for (int count{ 1 }; count <= 10; ++count)
	{
		// We can also directly access Random::mt
		std::cout << die6(Random::mt) << '\t'; // generate a roll of the die here
	}

	return 0;


}