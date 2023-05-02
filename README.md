# Pseudo-random number generators (PRNGs)

To simulate randomness, programs typically use a pseudo-random number generator. A pseudo-random number generator (PRNG) is an algorithm that generates a sequence of numbers whose properties simulate a sequence of random numbers.

When a PRNG is instantiated, an initial value (or set of values) called a random seed (or seed for short) can be provided to initialize the state of the PRNG. When a PRNG has been initialized with a seed, we say it has been seeded.

Most PRNGs that produce quality results use at least 16 bytes of state, if not significantly more. However, the size of the seed value can be smaller than the size of the state of the PRNG. When this happens, we say the PRNG has been underseeded.

# Mersenne Twister 

1) Generating random numbers in C++ using Mersenne Twister

The Mersenne Twister PRNG, besides having a great name, is probably the most popular PRNG across all programming languages. 
The random library has support for two Mersenne Twister types:

mt19937 is a Mersenne Twister that generates 32-bit unsigned integers
mt19937_64 is a Mersenne Twister that generates 64-bit unsigned integers

2) Rolling a dice with Mersenne Twister

A 32-bit PRNG will generate random numbers between 0 and 4,294,967,295, but we do not always want numbers in that range. If our program was simulating a board game or a dice game, we’d probably want to simulate the roll of a 6-sided dice by generating random numbers between 1 and 6. If our program was a dungeon adventure, and the player had a sword that did between 7 and 11 damage to monsters, then we’d want to generate random numbers between 7 and 11 whenever the player hit a monster.

While each number in the sequence is random with regards to the previous one, the entire sequence is not random at all! Each run of our program produces the exact same result.

In order to make our entire sequence randomized differently each time the program is run, we need to pick a seed that’s not a fixed number. The first answer that probably comes to mind is that we need a random number for our seed! That’s a good thought, but if we need a random number to generate random numbers, then we’re in a catch-22. It turns out, we really don’t need our seed to be a random number -- we just need to pick something that changes each time the program is run. Then we can use our PRNG to generate a unique sequence of pseudo-random numbers from that seed.

There are two methods that are commonly used to do this:
    Use the system clock or Use the system’s random device
    
3) Solution to underseeding issues of Mersenne Twister

The internal state of a Mersenne Twister is 624 bytes in size. Using the system clock or system's random device are temporary solutions only so our seed is only a single 32-bit integer. This means we’re essentially initializing a 624-byte object with a 4-byte value, which is significantly underseeding the Mersenne Twister PRNG. Underseeded PRNG can generate results that are suboptimal for applications that need the highest quality results. For example, seeding "std::mt19937" with a single 32-bit value will never generate the number 42 as its first output.

The solution to this is to use std::seed_seq, a type that performs two functions.  So if you initialize std::seed_seq with a single 32-bit integer (e.g. from std::random_device) and then initialize a Mersenne Twister with the std::seed_seq object, std::seed_seq will generate 620 bytes of additional seed data which is better than nothing.

