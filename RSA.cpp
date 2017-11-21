//
// Created by Rushil on 11/20/2017.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int gcd(int m, int n)
{
    if (n == 0)
    {
        return m;
    }

    return gcd(n, m % n);
}

double encrypt(double p, double e, double n)
{
    return fmod(pow(p, e), n);

}

double decrypt(double c, double d, double n)
{
    return fmod(pow(c, d) ,n);
}


int main()
{
    //Primes
    double p = 3;
    double q = 7;

    //Encryption Modulus
    double n = p * q;

    //Phi Val
    double phi = (p - 1) * (q - 1);

    double e = 2;

    //The Co-Prime Thing
    while(e < phi)
    {
        if(gcd(e, phi) == 1)
        {
            break;
        }

        else
        {
            e++;
        }
    }

    double k = 2; //Constant
    double d = (1 + (k * phi)) / e;

    cout << "Encryption - " << encrypt(12, e, n) << endl;

    cout << "Decryption - " << decrypt(encrypt(12, e, n), d, n) << endl;

}
