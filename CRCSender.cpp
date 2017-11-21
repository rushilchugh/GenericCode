//
// Created by Rushil on 11/20/2017.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{

    string msg, crc, encoded = "";

    cout << "Enter The Message - ";
    cin >> msg;

    cout << "Enter The CRC Generator Polynomial- ";
    cin >> crc;

    int m = msg.length();
    int n = crc.length();

    encoded += msg;

    //Appending Zeroes
    for (int i = 0; i < crc.length() - 1; i++)
    {
        encoded.push_back('0');
    }


    //XORing Here
    for (int i = 0; i < encoded.length() - n + 1;)
    {
        for(int j = 0; j < n; j++)
        {
            encoded[i + j] = encoded[i + j] == crc[j] ? '0' : '1';
        }

        for (; i < encoded.length() && encoded[i] != '1'; i++);
    }

    cout << msg + encoded.substr(encoded.length() - n + 1);


    return 0;
}