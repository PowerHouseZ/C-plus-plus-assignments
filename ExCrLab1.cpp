#include <iostream>

using namespace std;

int main() {
    string userFirstName;
    string userLastName;
    int sum;
    int num;
    int average;

    cout << "Please Enter your first and last name: " << endl;
    cin >> userFirstName >> userLastName;
    cout << endl;

    for (int i = 1; i <= 5; i++) {

        cout << "Now keep entering an integer until you reach your 5th input: " << endl;
        cin >> num;
        sum = sum + num;
    }

    average = sum / 5;

    cout << "Hello " << userFirstName << " " << userLastName << "." << endl <<
    "Your average for the integers you entered is " << average << "." << endl;

    return 0;
}
