#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
node *head, *tail;
int sizeOfList();
void addBeginning(int key)
{
    node *newNode;
    newNode = new node;
    newNode->data = key;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void addEnding(int key)
{
    node *newNode = new node;
    newNode->data = key;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void addAny(int key, int pos)
{
    int c = sizeOfList();
    if (pos == 0)
    {
        addBeginning(key);
        return;
    }
    else if (pos == c)
    {
        addEnding(key);
        return;
    }
    else if (pos > c)
    {
        cout << "Position is longer than the size of list.\n";
    }
    else
    {
        node *newNode = new node;
        newNode->data = key;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            node *temp1 = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = temp1;
            temp1->prev = newNode;
        }
    }
}
void deleteBeginning()
{
    if (head == NULL)
    {
        cout << "List has not been created.\n";
    }
    else
    {
        node *temp = head;
        if (sizeOfList() == 1)
        {
            head = NULL;
        }
        else
        {
            head = head->next;
        }
        delete[] temp;
    }
}
void deleteEnding()
{
    if (head == NULL)
    {
        cout << "List has not been created.\n";
    }
    else if (sizeOfList() == 1)
    {
        deleteBeginning();
        return;
    }
    else
    {
        node *temp = tail->prev;
        delete[] tail;
        tail = temp;
        tail->next = NULL;
    }
}
void deleteAny(int pos)
{
    if (head == NULL)
    {
        cout << "List has not been created.\n";
    }
    else if (pos == 0)
    {
        deleteBeginning();
        return;
    }
    else if (pos == sizeOfList() - 1)
    {
        deleteEnding();
        return;
    }
    else if (pos > sizeOfList())
    {
        cout << "Position is longer than the size of list.\n";
    }
    else
    {
        node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        node *toDelete = temp->next;
        node *newNext = temp->next->next;
        delete[] toDelete;
        temp->next = newNext;
    }
}
void updateBeginning(int newVal)
{
    if (head == NULL)
    {
        cout << "List has not been created. So this will add the value instead of update.\n";
        addBeginning(newVal);
    }
    else
    {
        head->data = newVal;
    }
}
void updateEnding(int newVal)
{
    if (head == NULL)
    {
        cout << "List has not been created. So this will add the value instead of update.\n";
        addEnding(newVal);
    }
    else
    {
        tail->data = newVal;
    }
}
void updateAny(int newVal, int pos)
{
    if (pos == 0)
    {
        updateBeginning(newVal);
        return;
    }
    else if (head == 0)
    {
        cout << "List has not been created.\n";
    }
    else
    {
        node *temp = head;
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->data = newVal;
    }
}
int sizeOfList()
{
    int c = 0;
    node *temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
int main()
{
    head = NULL, tail = NULL;
    while (1)
    {
        cout << "1. Add \n2. Update\n3. Delete\n4. Display the list\n5. Display the size\n6. isEmpty\n7. Reverse the list\n0. End" << endl;
        int x;
        cin >> x;
        if (x == 1)
        {
            cout << "1. Add beginning \n2. Add Ending\n3. Add at any point" << endl;
            int y;
            cin >> y;
            if (y == 1)
            {
                cout << "Enter a value: ";
                int key;
                cin >> key;
                addBeginning(key);
            }
            else if (y == 2)
            {
                cout << "Enter a value: ";
                int key;
                cin >> key;
                addEnding(key);
            }
            else if (y == 3)
            {
                cout << "Enter a value: ";
                int key, pos;
                cin >> key;
                cout << "\nEnter position: ";
                cin >> pos;
                addAny(key, pos);
            }
        }
        else if (x == 2)
        {
            cout << "1. Update beginning \n2. Update Ending\n3. Update at any point" << endl;
            int y;
            cin >> y;
            if (y == 1)
            {
                cout << "Enter a value: ";
                int key;
                cin >> key;
                updateBeginning(key);
            }
            else if (y == 2)
            {
                cout << "Enter a value: ";
                int key;
                cin >> key;
                updateEnding(key);
            }
            else if (y == 3)
            {
                cout << "Enter a value: ";
                int key, pos;
                cin >> key;
                cout << "\nEnter position: ";
                cin >> pos;
                updateAny(key, pos);
            }
        }
        else if (x == 3)
        {
            cout << "1. Delete beginning \n2. Delete Ending\n3. Delete at any point" << endl;
            int y;
            cin >> y;
            if (y == 1)
            {
                deleteBeginning();
            }
            else if (y == 2)
            {
                deleteEnding();
            }
            else if (y == 3)
            {
                int pos;
                cout << "Enter position: ";
                cin >> pos;
                deleteAny(pos);
            }
        }
        else if (x == 4)
        {
            if (head == NULL)
            {
                cout << "The list has not been created yet!!!" << endl;
            }
            else
            {
                cout << "The list is: ";
                node *temp = head;
                while (temp != NULL)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
        else if (x == 5)
        {
            cout << "The size of the array is: " << sizeOfList() << endl;
        }
        else if (x == 6)
        {
            if (head == NULL)
            {
                cout << "The list is Empty" << endl;
            }
            else
            {
                cout << "The list is not empty" << endl;
            }
        }
        else if (x == 7)
        {
            if (head == NULL)
            {
                cout << "The list is Empty" << endl;
            }
            else
            {
                node *current = head;
                node *temp = NULL;
                while (current != NULL)
                {
                    temp = current->prev;
                    current->prev = current->next;
                    current->next = temp;
                    current = current->prev;
                }
                if (temp != NULL)
                {
                    head = temp->prev;
                }
                tail = head;
                cout << "The list has been reversed." <<endl;
                cout << "The list is: ";
                node *temp2 = head;
                while (temp2 != NULL)
                {
                    cout << temp2->data << " ";
                    temp2 = temp2->next;
                }
                cout << endl;
            }
        }
        else if (x == 0)
        {
            break;
        }
        else
        {
            cout << "Please enter a valid key to operate!!!\n";
        }
    }
}
