// Program to Insert node at nth position in a linked list
// Time Complexity - O(N)

#include <iostream>
using namespace std;

struct Node
{
    //To store the element
    int data;
    //To store the address of next element
    Node *next;
};

//Pointer to head Node initialize to NULL
Node *head = NULL;

void insertAtNthNode(int x, int n)
{
    //Extra space for new Node
    Node *temp = (Node *)malloc(sizeof(Node));

    //Store the value in the Node
    temp->data = x;

    //Initialize address as NULL
    temp->next = NULL;

    //If Insertion taking place at Beginning
    if (n == 1)
    {
        temp->next = head;
        head = temp; //It Point Head Node
        return;
    }

    //To connect link with (n-1)th Node
    Node *temp1 = head;

    //Iterate to get (n-1)th Node address
    for (int i = 0; i < n - 2; i++)
        temp1 = temp1->next;

    //Store new address
    temp->next = temp1->next;

    temp1->next = temp;
}

void PrintList()
{
    //Initialize to Head Node
    Node *temp = head;

    cout << "\nList is : ";

    //Print until Last node
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

int main()
{
    int n, x, op;
    while (true)
    {
        cout << "\n"
             << "Enter 1 for insertion\n"
             << "2 for Priniting List\n"
             << "3 for Quit|\n";
        cin >> op;

        if (op == 1)
        {
            cout << "Enter Number and its position : ";
            cin >> n >> x;
            insertAtNthNode(n, x);
        }
        else if (op == 2)
            PrintList();
        else
            break;
    }

    return 0;
}