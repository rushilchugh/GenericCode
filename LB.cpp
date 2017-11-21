//
// Created by Rushil on 11/21/2017.
//

#include <iostream>

using namespace std;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int sub(int a, int b)
{
    return (a - b) > 0 ? (a - b) : 0;
}

int main()
{
    int bucket = 0, op_rate, bsize, pkt[10], n;

    cout << "Enter Number of Packets - ";
    cin >> n;

    cout << "Enter Bucket Size - ";
    cin >> bsize;

    cout << "Enter Output Rate - ";
    cin >> op_rate;

    cout << "Enter Arriving Packets - ";

    for(int i = 0; i < n; i++)
    {
        cin >> pkt[i];
    }

    cout << "\n Second \t Size \t Bucket \t Accept/Reject \t Packet_Send";
    cout << "\n ------------------------------ \n";

    int i;

    for(i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << pkt[i] << "\t";

        if(bucket + pkt[i] <= bsize)
        {
            bucket += pkt[i];
            cout << bucket << "\t" << "Accept\t" << min(bucket, op_rate) << endl;
            bucket = sub(bucket, op_rate);
        }

        else
        {
            cout << bucket << "\t" << "Reject\t" << min(bsize, op_rate) << endl;
            bucket = sub(bucket, op_rate);

        }
    }

    while (bucket != 0)
    {
        cout << i++ << "\t0\tAccept" << bucket;
        bucket = sub(bucket, op_rate);
    }

    return 0;

}
