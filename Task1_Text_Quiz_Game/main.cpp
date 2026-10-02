#include <iostream>
using namespace std;

int main() {

    int score = 0;
    int answer;

    cout << "=====================================\n";
    cout << "       COGNIFYZ QUIZ GAME\n";
    cout << "=====================================\n";

    cout << "\nQuestion 1:\n";
    cout << "Which language are we using for this project?\n";
    cout << "1. Python\n";
    cout << "2. Java\n";
    cout << "3. C++\n";
    cout << "4. HTML\n";

    cout << "Enter your answer: ";
    cin >> answer;

    if (answer == 3) {
        cout << "Correct!\n";
        score++;
    }
    else {
        cout << "Wrong answer!\n";
    }

    cout << "\nQuestion 2:\n";
    cout << "Which keyword is used to make a decision in C++?\n";
    cout << "1. if\n";
    cout << "2. loop\n";
    cout << "3. print\n";
    cout << "4. input\n";

    cout << "Enter your answer: ";
    cin >> answer;

    if (answer == 1) {
        cout << "Correct!\n";
        score++;
    }
    else {
        cout << "Wrong answer!\n";
    }

    cout << "\nQuestion 3:\n";
    cout << "Which symbol is used to end a C++ statement?\n";
    cout << "1. :\n";
    cout << "2. ;\n";
    cout << "3. .\n";
    cout << "4. ,\n";

    cout << "Enter your answer: ";
    cin >> answer;

    if (answer == 2) {
        cout << "Correct!\n";
        score++;
    }
    else {
        cout << "Wrong answer!\n";
    }

    cout << "\n=====================================\n";
    cout << "             QUIZ RESULT\n";
    cout << "=====================================\n";

    cout << "Your score: " << score << " / 3\n";

    if (score == 3) {
        cout << "Excellent!\n";
    }
    else if (score == 2) {
        cout << "Good job!\n";
    }
    else if (score == 1) {
        cout << "Keep practicing!\n";
    }
    else {
        cout << "Don't give up. Try again!\n";
    }

    return 0;
}
