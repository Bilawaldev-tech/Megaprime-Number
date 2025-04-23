# Mega Prime Finder

This project is a C++ program to find all **megaprime numbers** up to a user-specified limit.

A **megaprime** is:
- A number that is prime.
- All of its digits are also **prime digits** (`2`, `3`, `5`, or `7`).

---

##  Example

-  53 is a megaprime → it's a prime, and digits 5 and 3 are also primes.
-  13 is **not** a megaprime → even though it's prime, digit 1 is not prime.
-  35 is **not** a megaprime → 35 is not a prime.

---

##  How to Run

###  Prerequisites

- A C++ compiler that supports C++11 or later (e.g. `g++`, `clang++`).

###  Compile and Run

```bash
g++ megaprime.cpp -o megaprime -std=c++11
./megaprime
