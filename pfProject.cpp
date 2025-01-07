#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct list {
    string name;
    int quantity;
};

const int MAX_LISTS = 100;
list lists[MAX_LISTS];
int listCount = 0;

void displaylists() {
    if (listCount == 0) {
        cout << "The grocery list is empty." << endl;
        return;
    }
    cout << "Grocery List:" << endl;
    for (int i = 0; i < listCount; i++) {
        cout << i + 1 << ". " << lists[i].name << " (" << lists[i].quantity << ")" << endl;
    }
}

void add() {
    if (listCount >= MAX_LISTS) {
        cout << "The grocery list is full." << endl;
        return;
    }

    cout << "Enter the name of the list: ";
    cin >> lists[listCount].name;
    cout << "Enter the quantity: ";
    cin >> lists[listCount].quantity;
    listCount++;
    cout << "Your lists are added!" << endl;
}

void edit() {
    displaylists();
    if (listCount == 0) return;

    int index;
    cout << "Enter the number of the list to edit: ";
    cin >> index;

    if (index < 1 || index > listCount) {
        cout << "Invalid." << endl;
        return;
    }

    --index;
    cout << "Enter the new name for the list: ";
    cin >> lists[index].name;
    cout << "Enter the new quantity: ";
    cin >> lists[index].quantity;
    cout << "Your list is updated" << endl;
}

void deletelist() {
    displaylists();
    if (listCount == 0) {
        return;
    }

    int index;
    cout << "Enter the number of the item on the list to be deleted: ";
    cin >> index;

    if (index < 1 || index > listCount) {
        cout << "invalid list number." << endl;
        return;
    }

    --index;
    for (int i = index; i < listCount - 1; ++i) {
        lists[i] = lists[i + 1];
    }

    --listCount;
    cout << "List deleted successfully!" << endl;
}

void saveToFile() {
    string filename;
    cout << "Enter the filename where you want to save the list: ";
    cin >> filename;

    ofstream file(filename);
    if (!file) {
        cout << "Error, can't open file." << endl;
        return;
    }

    for (int i = 0; i < listCount; ++i) {
        file << lists[i].name << "," << lists[i].quantity << endl;
    }

    file.close();
    cout << "Grocery list saved successfully to " << filename << endl;
}

void showMenu() {
    int choice;
    do {
        cout << "Grocery List Manager: " << endl;
        cout << "1. Add list" << endl;
        cout << "2. Edit list" << endl;
        cout << "3. Delete list" << endl;
        cout << "4. Save List to File" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            deletelist();
            break;
        case 4:
            saveToFile();
            break;
        case 5:
            cout << "Program is ended!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);
}

int main() {
    showMenu();
    return 0;
}
