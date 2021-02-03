#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int generateRandomNumber();
int getPlayerGuess(int guess, int& count);
void printAnswer(int guess, int secretNumber);
void playGuessIt();

int main (){
    srand(time(0));
    int secretNumber = generateRandomNumber();
    int guess,count = 0, score = 10000, n = 100;
    do {
        guess = getPlayerGuess(guess,count);
        score -= 2*n;
        n--;
        printAnswer(guess,secretNumber);

    } while (guess != secretNumber);
    cout << "Your score is " << score << endl;
    playGuessIt();
    return 0;
}

void playGuessIt(){
    cout << "Play again?" << endl;
    char ch;
    cin >> ch;
    if (ch == 'Y') main();
}
int generateRandomNumber()
{
    return rand() % 100 + 1;
}
int getPlayerGuess(int guess, int& count)
{
    count++;
    cout << count << " Enter your guess ";
    cin >> guess;
    return guess;
}
void printAnswer(int guess, int secretNumber)
{
    if (guess > secretNumber) cout << "Your number is too big." << endl;
    else if (guess < secretNumber) cout << "Your number is too small." << endl;
    else cout << "You won. " ;
}
