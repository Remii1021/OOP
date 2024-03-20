#include <iostream>
#include "Container.h"
#include "LList.h"
#include "DLList.h"

void testLList() {
    // Create an LList object
    LList myList;

    // Test constructor
    std::cout << "\n** Testing Constructor (default): **\n";
    myList = LList(); // Default constructor (empty list)
    std::cout << "List size: " << myList.getSize() << std::endl;

    // Test push function
    std::cout << "\n** Testing push function: **\n";
    myList.push(10);
    myList.push(20);
    myList.push(30);
    std::cout << "List after push: \n";
    myList.print();

    // Test getSize function
    std::cout << "\n** Testing getSize function: **\n";
    int size = myList.getSize();
    std::cout << "List size: " << size << std::endl;

    // Test getData function (valid and invalid index)
    std::cout << "\n** Testing getData function: **\n";
    int value = myList.getData(1); // Valid index
    std::cout << "Value at index 1: " << value << std::endl;
    value = myList.getData(4); // Invalid index
    if (value == 0) {
        std::cout << "Error: Index out of range." << std::endl;
    }

    // Test insert function (beginning, middle, end)
    std::cout << "\n** Testing insert function: **\n";
    myList.insert(5, 0); // Insert at beginning
    myList.insert(15, 2); // Insert in middle
    myList.insert(40, size); // Insert at end (use getSize to get current size)
    std::cout << "List after insert: \n";
    myList.print();

    // Test del function (beginning, middle, end)
    std::cout << "\n** Testing del function: **\n";
    myList.del(0); // Delete from beginning
    myList.del(2); // Delete from middle
    myList.del(size - 1); // Delete from end (use getSize - 1 for last index)
    std::cout << "List after delete: \n";
    myList.print();

    // Test operator[] (valid and invalid index)
    std::cout << "\n** Testing operator[]: **\n";
    value = myList[1]; // Valid index
    std::cout << "Value at index 1: " << value << std::endl;
    try {
        value = myList[size]; // Invalid index (using try-catch for potential out-of-bounds errors)
        std::cout << "Value at index " << size << ": " << value << std::endl; // This shouldn't print if the function throws an exception for invalid index
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    myList[1] = 9;
    LList myList2(myList);
    LList myList3 = myList + myList2;
    myList3.print();
}
void testDLList() {
    // Create a DLList object
    DLList myList;

    // Test constructor (default): 
    std::cout << "\n** Testing Constructor (default): **\n";
    myList = DLList(); // Default constructor (empty list)
    std::cout << "List size: " << myList.getSize() << std::endl;

    // Test push function
    std::cout << "\n** Testing push function: **\n";
    myList.push(10);
    myList.push(20);
    myList.push(30);
    std::cout << "List after push: \n";
    myList.print();

    // Test getSize function
    std::cout << "\n** Testing getSize function: **\n";
    int size = myList.getSize();
    std::cout << "List size: " << size << std::endl;

    // Test getData function (valid and invalid index)
    std::cout << "\n** Testing getData function: **\n";
    int value = myList.getData(1); // Valid index
    std::cout << "Value at index 1: " << value << std::endl;
    value = myList.getData(4); // Invalid index
    if (value == 0) {
        std::cout << "Error: Index out of range." << std::endl;
    }

    // Test insert function (beginning, middle, end)
    std::cout << "\n** Testing insert function: **\n";
    myList.insert(5, 0); // Insert at beginning
    myList.insert(15, 2); // Insert in middle
    myList.insert(40, myList.getSize()); // Insert at end (use getSize to get current size)
    std::cout << "List after insert: \n";
    myList.print();

    // Test del function (beginning, middle, end)
    std::cout << "\n** Testing del function: **\n";
    myList.del(0); // Delete from beginning
    myList.print();
    myList.del(2); // Delete from middle
    myList.print();
    myList.del(myList.getSize() - 1); // Delete from end (use getSize - 1 for last index)
    myList.print();
    std::cout << "List after delete: \n";
    myList.print();

    // Test operator[] (valid and invalid index)
    std::cout << "\n** Testing operator[]: **\n";
    value = myList[1]; // Valid index
    std::cout << "Value at index 1: " << value << std::endl;
    try {
        value = myList[size]; // Invalid index (using try-catch for potential out-of-bounds errors)
        std::cout << "Value at index " << size << ": " << value << std::endl; // This shouldn't print if the function throws an exception for invalid index
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    myList[1] = 9;
    DLList myList2(myList);
    {

        DLList myList3 = myList + myList2;
        myList3.print();
    }
}


int main() {
    int choice, listType;

    do {
        std::cout << "\n** Menu for Container Class Testing **\n";
        std::cout << "1. Test LList Class\n";
        std::cout << "2. Test DLList Class\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1 || choice == 2) {
            std::cout << "\n** Choose List Type (for " << (choice == 1 ? "LList" : "DLList") << "):**\n";
            std::cout << "1. Singly Linked List\n";
            std::cout << "2. Doubly Linked List\n";
            std::cout << "Enter your choice: ";
            std::cin >> listType;
        }

        switch (choice) {
        case 1: // LList Testing
            if (listType == 1) {
                testLList(); // Function to test functionalities of Singly Linked List (LList)
            }
            else {
                std::cerr << "Invalid list type choice for LList." << std::endl;
            }
            break;
        case 2: // DLList Testing
            if (listType == 2) {
                testDLList(); // Function to test functionalities of Doubly Linked List (DLList)
            }
            else {
                std::cerr << "Invalid list type choice for DLList." << std::endl;
            }
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
