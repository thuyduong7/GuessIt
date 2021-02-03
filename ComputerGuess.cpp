#include <iostream>
using namespace std;
char getHostAnswer(int x);
int selectNumber(int low, int high);

int main()
{
    int x, low = 1, high = 100;
    char answer;
    do {
        x = selectNumber(low,high);
        answer = getHostAnswer(x);
        if (answer == '>') high = x - 1;
        else if (answer == '<') low = x + 1;
    } while (answer != '=');
    cout << "Your number is " << x << endl;
    return 0;
}

int selectNumber(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

char getHostAnswer(int x)
{
    char answer;
    cout << "Is " << x << " your number?" << endl;
    cin >> answer;
    return answer;
}
