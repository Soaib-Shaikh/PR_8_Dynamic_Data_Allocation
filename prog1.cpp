#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;       
};

class LinkList{
    public: 
        int size;
        Node* head;

    LinkList(){
        head = NULL;
        size = 0;
    }

    void insertAtFront(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        size++;
    }

    void searchindex(int index){
        if (index == 0)
        {
            cout<<head->data<<endl;
        }
        else if(index > 0 && index <= size)
        {
            Node* temp = head;
            for (int i = 0; i < index ; i++)
            {
                temp = temp->next;
            }
            cout << "Element at index " << index << " is: " << temp->data << endl;
        }
    }

    void deleteAtindex(int index){
           if(index == 0)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
                size--;
            }
            else if(index > 0 && index <= size)
            {
                Node* temp = head;
                for (int i = 0; i < index - 1; i++)
                {
                    temp = temp->next;
                }
                Node* toDelete = temp->next;
                temp->next = toDelete->next;
                delete toDelete;
                size--;
            }     
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = this->head;
        while (current) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        this->head = prev;
    }


    void displayData(){
        Node* current = head;
        cout << "LinkList: ";
        while(current != NULL){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
        cout << endl;
    }
};

int main(){

    LinkList list;
    int choice;

    do
    {
        cout<<"========== Dynamic Data Structure ==========="<<endl;
        cout<<"1. Insert at front"<<endl;
        cout<<"2. Search"<<endl;
        cout<<"3. Delete"<<endl;
        cout<<"4. Reverse"<<endl;
        cout<<"5. Display List"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"============================================="<<endl;
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;

        switch (choice)
        {
        case 1:             
            int data;
            cout << "Enter data to insert at front: ";
            cin >> data;
            list.insertAtFront(data);
            list.displayData();
            break;

        case 2:
            int serIndex;
            cout << "Enter index to search: ";
            cin >> serIndex;
            list.searchindex(serIndex);
            cout << "After searching: ";
            list.displayData();
            break;

        case 3:
            int delIndex;
            cout << "Enter index to delete: ";
            cin >> delIndex;
            list.deleteAtindex(delIndex);
            cout << "After deletion: ";
            list.displayData();
            break;

        case 4:
            list.reverse();
            cout << "After reversing: ";
            list.displayData();
            break;

        case 5:
            list.displayData();
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);
    
    return 0;
}