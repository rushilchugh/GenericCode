//
// Created by Rushil on 11/21/2017.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string msg, crc, encoded;

    cout << "Enter Encoded Message- ";
    cin >> encoded;

    cout << "Enter CRC - ";
    cin >> crc;

    int m = msg.length();
    int n = crc.length();

    for(int i = 0; i < encoded.length() - n + 1;)
    {
        for (int j = 0; j < crc.length(); j++)
        {
            encoded[i + j] = encoded[i + j] == crc[j] ? '0' : '1';
        }

        for(; i < encoded.length() && encoded[i] != '1'; i++);
    }

    cout << encoded;


    return 0;

}
