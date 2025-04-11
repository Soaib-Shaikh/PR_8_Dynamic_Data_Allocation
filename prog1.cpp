#include<iostream>
using namespace std;

// Node class represents a single element in the linked list
class Node {
    public:
        int data; // Data stored in the node
        Node* next; // Pointer to the next node in the list
};

// LinkList class represents the linked list and its operations
class LinkList {
    public: 
        int size; // Tracks the number of elements in the list
        Node* head; // Pointer to the first node in the list

    // Constructor initializes an empty linked list
    LinkList() {
        head = NULL; // Head is null when the list is empty
        size = 0; // Size is initially 0
    }

    // Inserts a new node at the front of the list
    void insertAtFront(int data) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = data; // Assign the data to the new node
        newNode->next = head; // Point the new node to the current head
        head = newNode; // Update the head to the new node
        size++; // Increment the size of the list
    }

    // Searches for an element by its index and displays it
    void searchindex(int index) {
        if (index == 0) {
            // If index is 0, display the data at the head
            cout << head->data << endl;
        } else if (index > 0 && index <= size) {
            // Traverse the list to find the element at the given index
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            cout << "Element at index " << index << " is: " << temp->data << endl;
        }
    }

    // Deletes a node at a specific index
    void deleteAtindex(int index) {
        if (index == 0) {
            // If index is 0, delete the head node
            Node* temp = head;
            head = head->next; // Update the head to the next node
            delete temp; // Free the memory of the old head
            size--; // Decrement the size
        } else if (index > 0 && index <= size) {
            // Traverse the list to find the node before the target
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node* toDelete = temp->next; // Node to be deleted
            temp->next = toDelete->next; // Update the link to skip the deleted node
            delete toDelete; // Free the memory of the deleted node
            size--; // Decrement the size
        }
    }

    // Reverses the linked list
    void reverse() {
        Node* prev = nullptr; // Initialize the previous pointer as null
        Node* current = this->head; // Start from the head
        while (current) {
            Node* next = current->next; // Store the next node
            current->next = prev; // Reverse the link
            prev = current; // Move the previous pointer forward
            current = next; // Move the current pointer forward
        }
        this->head = prev; // Update the head to the new first node
    }

    // Displays all the elements in the linked list
    void displayData() {
        Node* current = head; // Start from the head
        cout << "LinkList: ";
        while (current != NULL) {
            cout << current->data << " "; // Print the data of each node
            current = current->next; // Move to the next node
        }
        cout << endl;
        cout << endl;
    }
};

// Main function to interact with the user
int main() {
    LinkList list; // Create a linked list object
    int choice; // Variable to store the user's menu choice

    do {
        // Display the menu
        cout << "========== Dynamic Data Structure ===========" << endl;
        cout << "1. Insert at front" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Reverse" << endl;
        cout << "5. Display List" << endl;
        cout << "0. Exit" << endl;
        cout << "=============================================" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice; // Get the user's choice
        cout << endl;

        switch (choice) {
            case 1:
                // Insert a new element at the front
                int data;
                cout << "Enter data to insert at front: ";
                cin >> data; // Get the data to insert
                list.insertAtFront(data); // Insert the data
                list.displayData(); // Display the updated list
                break;

            case 2:
                // Search for an element by index
                int serIndex;
                cout << "Enter index to search: ";
                cin >> serIndex; // Get the index to search
                list.searchindex(serIndex); // Search for the index
                cout << "After searching: ";
                list.displayData(); // Display the list
                break;

            case 3:
                // Delete an element by index
                int delIndex;
                cout << "Enter index to delete: ";
                cin >> delIndex; // Get the index to delete
                list.deleteAtindex(delIndex); // Delete the node at the index
                cout << "After deletion: ";
                list.displayData(); // Display the updated list
                break;

            case 4:
                // Reverse the linked list
                list.reverse(); // Reverse the list
                cout << "After reversing: ";
                list.displayData(); // Display the reversed list
                break;

            case 5:
                // Display the current state of the list
                list.displayData();
                break;

            case 0:
                // Exit the program
                cout << "Exiting..." << endl;
                break;

            default:
                // Handle invalid input
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0); // Repeat until the user chooses to exit

    return 0;
}