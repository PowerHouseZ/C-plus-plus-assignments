#include <iostream>
#include <iomanip>

using namespace std;

template <class elemType>
int binarySearch(const elemType list[], int length, const elemType& item)
{
    int first = 0;
    int last = length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (list[mid] == item)
            found = true;
        else if (list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found)
        return mid;
    else
        return -1;
}

void selectionSort(int list[], int length)
{
    int index;
    int smallestIndex;
    int location;
    int temp;

    for (index = 0; index < length - 1; index++)
    {
        smallestIndex = index;

        for (location = index + 1; location < length; location++)
            if (list[location] < list[smallestIndex])
                smallestIndex = location;


        temp = list[smallestIndex];
        list[smallestIndex] = list[index];
        list[index] = temp;
    }

}

void showSelection(){

    cout << "*** Binary Search for 10 integers in a list ***" << endl;
    cout << "1. Enter 10 numbers into a list " << endl;
    cout << "2. Search for a number on the list " << endl;
    cout << "3. Print the list " << endl;
    cout << "4. Exit " << endl;
}

int main() {

    showSelection();

    int choice;
    int index;
    int intList[10];
    int pos;
    int i;

    cin >> choice;

    while (choice != 4) {
        switch (choice) {
            case 1:

                cout << fixed << showpoint << setprecision(2);

                cout << "Enter 10 numbers from 1-10 to be place within the list: " << endl;

                for (index = 0; index < 10; index++) {

                    cin >> intList[index];

                    cout << endl;
                    }
                    break;
                    case 2:

                        cout << "Enter the a number from the list to see where it's located on the list: "
                        << endl;
                        cin >> intList[index];

                cout << "After sorting the numbers from smallest to largest- " << endl;

                    for (i = 0; i < 10; i++)

                        pos = binarySearch(intList, 10, intList[index]);

                    if (pos != -1)
                        cout << "The number: " << intList[index] << " is found at position "
                             << pos + 1 << endl;
                    else
                        cout << "The number: " << intList[index]
                             << " is not in intList " << endl;
                    break;
                    case 3:
                        cout << "The numbers on the list are: " << endl;

                    if (intList[index] == 0) {
                        cout << "Empty list! Please select option 1 to input numbers into the list. "
                        << endl;
                    } else

                        for (i = 0; i < 10; i++)
                            cout << intList[i] << " " << endl;
                    break;
                    default:
                        cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid option, please enter either 1, 2, or 3. \n" << endl;
                }
                showSelection();
                cin >> choice;
                selectionSort(intList, 10);
        }
        return 0;
    }






