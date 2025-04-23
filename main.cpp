/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector>


/******************************************************************************
 * @file    megaprime.cpp
 * @brief   Program to identify and print mega prime numbers up to a given limit.
 *
 * A mega prime is a prime number where every digit is also a prime digit
 * (i.e., 2, 3, 5, 7). This program checks for prime and mega prime numbers 
 * within a user-specified range.
 ******************************************************************************/
#define UNSIGNED_INT_MAX  0xFFFFFFFF


//==============================================================================
//                               FUNCTIONS
//==============================================================================

//==============================================================================
/**
 * Function     isprime
 * @brief       Checks if a given number is a prime number.
 * @param       number The integer to check.
 * @return      true if the number is prime
 *              false if number is not prime
 */
//==============================================================================
static bool isprime(unsigned int number)
{
    int i;
    bool p_flag = true;
    if(number <= 1)
    {
        p_flag = false;
    }
    else
    {
        for (i = 2; i*i<= number; i++)
        {
            if(number % i == 0)
            {
                p_flag = false;
                break;
            }
        }
    }
    return p_flag;
}
//==============================================================================
/**
 * Function     ismegaprime
 * @brief       Checks if a given number is a megaprime number.
 * @param       number The integer to check.
 * @return      true if the number is megaprime
 *              false if number is not megaprime
 */
//==============================================================================
static bool ismegaprime(unsigned int number)
{
    bool m_prime_flag = true;
    int unit_index;

    if(!isprime(number))
    {
        m_prime_flag = false;
    }
    else
    {
        while(number > 0)
        {
            unit_index = number % 10;
            if(isprime(unit_index))
            {
                number = number / 10;
            }
            else 
            {
                break;
            }
        }       
        if(number != 0)
        {
            m_prime_flag = false;
        }
    }
    return m_prime_flag;
}
//==============================================================================
/**
 * function     find_megaprime_numbers
 * @brief       Insert all mega prime numbers from 2 up to the specified limit.
 *              into vector.
 * @param       number The upper limit of the range to search for 
 *              mega prime numbers.
 * @return      it returns the vector of all the megaprime numbers.
 */
//==============================================================================
static std::vector<unsigned int> find_megaprime_numbers(unsigned int number)
{
    int i;
    std::vector<unsigned int> megaprimes ;
    for(i=2; i<=number ; i++)
    {
        if(ismegaprime(i))
        {
            megaprimes.push_back(i);
        }
    }
    return megaprimes;
}
//==============================================================================
/**
 * function     print_megaprime_numbers
 * @brief       Insert all mega prime numbers from 2 up to the specified limit.
 *              into vector.
 * @param       vector that stores all the mega prime numbers.
 * @return      void
 */
//==============================================================================
static void print_megaprime_numbers(std::vector<unsigned int> &megaprimes)
{
    int i;
    std::cout << "[" ;
    for(auto it = megaprimes.begin() ; it != megaprimes.end() ; ++it)
    {
       std::cout << *it;
       if(next(it) != megaprimes.end())
       {
           std::cout << "," ;
       }
    }
    std::cout << "]";
}
//==============================================================================
/**
 * function     main()
 * @brief       Main function that starts program execution.
 *              Prompts the user to enter a maximum number and prints all
 *              mega primes up to that number if it is valid.
 * @param       void
 * @return      int Exit status of the program.
 */
//==============================================================================
int main()
{
    unsigned int maxnum;
    std::vector <unsigned int> mega_primes;
    std::cout <<"Unsigned integer:" << std::endl;
    std::cin >> maxnum;
    if(maxnum >= 0 && maxnum <= UNSIGNED_INT_MAX)
    {
        mega_primes = find_megaprime_numbers(maxnum);
        print_megaprime_numbers(mega_primes); 
    }
    else
    {
        std::cout << "Invalid Number (Range should be between 0 - 4294967295)" << std::endl;
    }
    return 0;
}

