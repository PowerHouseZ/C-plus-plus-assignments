#include <iostream>
#include <iomanip>

using namespace std;

void menuOptions();
void initializetestScoresArray(int list []);
void selectionSort(int list[], int length);

int main()
{
    int test[5]{};
    int choice = 0;
    int yourList[5]{};
    
    do 
    {
        menuOptions();
        cin >> choice;
        cin.clear();
        cin.ignore('A,', '\n');
        cout << endl;
   
        switch (choice)
        {

        case 1:
            initializetestScoresArray(test);
        break;
        
        case 2:
            selectionSort(yourList, 5);
           break;

        case 3:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "\nInvalid input. \n" << endl;
        }
            } 
            while (choice != 3);

            return 0;
}

void menuOptions()
{
    cout << "\nMenu Options \n" << endl;
    cout << "\n1. Enter 5 test scores and calculate the average. \n" << endl;
    cout << "\n2. Sort the list of scores from smallest to largest. \n" << endl;
    cout << "\n3. Exit.\n" << endl;
    cout << "\nEnter a choice: ";
}

void initializetestScoresArray(int list[])
{
    int test[5]{};
    int sum = 0;
    double average;
    int index = 0;

    cout << fixed << showpoint << setprecision(2);

        cout << "\nEnter 5 test scores to calculate the average: \n";

        for (index = 0; index < 5; index++)
        {
            cin >> test[index];
            sum = sum + test[index];

            if (test[index] >= 101)
                cout << "Invalid test score. \n";
            else
                cout << endl;
        }
        cout << endl;
        average = sum / 5.0;

        cout << "The average test score = " << average << endl;

        for (index = 0; index < 5; index++)

            if (test[index] < average)
                cout << test[index]
                << " is less than the average test score." << endl;

        if (average >= 101)
            cout << "\nInvalid average test score! \n";
        else
            cout << endl;
        }
    
void selectionSort(int list[], int length)
{
    int index{};
    int smallestIndex;
    int location;
    int temp;
    int yourList[5]{};

    cout << "\nSort the list of scores from smallest to largest: \n";

    for (int index = 0; index < 5; index++)
        cin >> yourList[index];

    if (yourList[index] == 0)
        cout << "\nCannot insert in a empty list. \n" << endl;
    else
        cout << "\nAfter sorting from smallest to largest, the list of scores are:  \n"
        << endl;

    for (int index = 0; index < 5; index++)
        cout << yourList[index] << " ";
    cout << endl;
    
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







