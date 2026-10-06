#include <iostream>
using namespace std;
int main() {
    int rows;
    cout << "=====================================\n";
    cout << "       NUMBER PATTERN GENERATOR\n";
    cout << "=====================================\n";
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "\nNumber Pattern:\n";
    for (int i = 1; i <= rows; i++) {

        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
