#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if(exp & 1)
    	result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

string smallestGoodBase(string n) {
    long num = stoi(n);
    long prime = long(pow(10, 9)) + 7;
    for(long m = log2(num); m >= 1; m--) {
        long k = pow(num, 1.0 / m);
        long sum = 0;
        for(long i = 0; i <= m; i++)
        	sum = (sum + modpow(k, i, prime)) % prime;
        if(num % prime == sum)
            return to_string(k);
    }
    return to_string(num - 1);
}
