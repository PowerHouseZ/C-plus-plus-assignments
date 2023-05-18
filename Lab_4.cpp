#include <iostream>

using namespace std;

struct IntNode
{
    int Num;
    IntNode* link;
};

void showSelection(){

    cout << "*** The Linked List That Stores Integers ***" << endl;
    cout << "1. Add a number to the list " << endl;
    cout << "2. Delete a number from list " << endl;
    cout << "3. Search for a number on the list " << endl;
    cout << "4. Print the list " << endl;
    cout << "5. Exit " << endl;
}

int main() {

    showSelection();

    int choice, number;
    int count = 0;

    bool found = false;

    IntNode* first = nullptr;
    IntNode* last = nullptr;
    IntNode* newNode, * current;

    cin >> choice;

    while (choice != 5) {
        switch (choice) {
            case 1:
                    newNode = new IntNode;
                    cout << "Enter a number to add to the list: ";
                    cin >> number;
                    newNode->Num = number;
                    newNode->link = nullptr;

                    if (first == nullptr)
                    {
                        first = newNode;
                        last = newNode;
                        count++;
                    }
                    else {
                        last->link = newNode;
                        last = newNode;
                        count++;
                    }
                    break;
                    case 2:
                        if (first == nullptr)
                            cout << "The list is empty\n";
                        else {
                            current = first;
                            first = first->link;
                            count--;

                            if (first == nullptr)
                                last = nullptr;

                            delete current;

                            cout << "Deleted a number from the list! " << endl;
                        }
                    break;
                    case 3:
                            current = first;

                            while (current != nullptr && !found)
                            {
                                if (current->Num >= number)
                                    found = true;
                                else
                                    current = current->link;

                                if (found)
                                    found = (current->Num == number);
                                cout << "The number is located in list" << current->Num << endl;

                            }
                break;
                    case 4:
                        if (first == nullptr)
                            cout << "The list is empty\n";
                        else {
                            current = first;
                            cout << "The list contains the following numbers: \n";
                            while (current != nullptr)
                            {
                                cout << current->Num << " ";
                                current = current->link;
                            }
                            cout << endl;
                        }
                break;
            default:
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid option, please enter either 1, 2, or 3. \n" << endl;
        }
        showSelection();
        cin >> choice;
    }
    return 0;
}






