#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void selectionSort(int list[], int length)
{
    int index;
    int smallestIndex;
    int location;
    int temp;

    for (index = 0; index < length -1; index++)
    {
        smallestIndex = index;

        for (location = index + 1; location < length; location++)
            if (list[location] < list [smallestIndex])
                smallestIndex = location;

        temp = list[smallestIndex];
        list[smallestIndex] = list [index];
        list[index] = temp;
    }
}

void showSelection(){

    cout << "*** Welcome to the Student Test Scores system ***" << endl;
    cout << "1. Test scores " << endl;
    cout << "2. Sort the list of scores from smallest to largest " << endl;
    cout << "3. Exit " << endl;
}

int main() {

    showSelection();

    int test[5];
    int sum = 0;
    double average;
    int index;
    int choice;
    int i;

    string str = "The input is not valid! Please enter a number from 0 - 100";

    cin >> choice;

    while (choice != 3) {
            switch (choice) {
                case 1:

                    do {

                        try {

                            cout << fixed << showpoint << setprecision(2);

                            cout << "Enter 5 test scores and calculate the average: " << endl;

                            for (index = 0; index < 5; index++)
                            {
                                cin >> test[index];

                                if (!cin)
                                    throw str;

                                while (test[index] < 0 || test[index] > 100) {
                                    cin.clear();
                                    cin.ignore(100, '\n');
                                    cout << "Invalid test score, please enter a number from 0 - 100 "
                                         << endl;
                                    cin >> test[index];
                                }
                                sum = sum + test[index];

                                cout << endl;

                                average = sum / 5.0;

                            }

                            cout << "The average of the test scores is = " << average << endl;
                        }
                            catch (string messageStr) {
                                cout << messageStr << endl;
                                cout << "Resetting the input state " << endl;
                                cin.clear();
                                cin.ignore(100, '\n');
                            }
                        }
                    while(cin.fail());
                    break;
                case 2:

                    cout << "After sorting from smallest to largest, the test scores are:" << endl;

                    if (test[index] == 0)
                    {
                        cout << "Empty list! Please enter option 1 to test scores. " << endl;
                    }
                    else

                    for (i = 0; i < 5; i++)
                        cout << test[i] << " " << endl;
                    break;
                default:
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid option, please enter either 1, 2, or 3. \n" << endl;
            }
            showSelection();
            cin >> choice;
            selectionSort(test, 5);

    }
        return 0;
}





