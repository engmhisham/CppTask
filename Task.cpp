
#include <iostream>

using namespace std;

int ReadNumber(string Message) {

    int Number;

    do
    {
        cout << Message;
        cin >> Number;

    } while (Number < 10 || Number > 20);

    return Number;
}

bool IsPrime(int Number) {

    int M = round(Number / 2);

    if (Number <= 1) 
        return false;

    if (Number == 2) 
        return true;

    for (int i = 2; i <= M; i++) {
        if (Number % i == 0)
            return false;
    }
    return true;
}

int FindNearestPrime(int num) {

    int Lower = num;
    int Upper = num;

    while (Lower > 1 && !IsPrime(Lower)) {
        Lower--;
    }

    while (!IsPrime(Upper)) {
        Upper++;
    }

    if (abs(num - Lower) <= abs(num - Upper)) {
        return Lower;
    }
    else {
        return Upper;
    }
}

void PrintResult(int Number, int NearestPrime)
{
    int Difference = abs(Number - NearestPrime);

    cout << "Nearest prime: " << NearestPrime << endl;
    cout << "Difference: " << Difference << endl;
}

int main()
{
    int Number = ReadNumber("Enter a number between 10 and 20: ");

    int NearestPrime = FindNearestPrime(Number);

    PrintResult(Number, NearestPrime);

    return 0;
}
