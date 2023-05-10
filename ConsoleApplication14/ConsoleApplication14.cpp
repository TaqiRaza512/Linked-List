#include<iostream>
using namespace std;
class Node
{
private:

public:
    int data;
    Node* Next;

    Node(int D = 0, Node* N = nullptr)
    {
        data = D;
        N = Next;
    }
};
class MyLinkedList
{

private:
    friend class Node;

    int size;
    Node* head;
    Node* tail;
public:

    bool IsEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }
    MyLinkedList()
    {
        head = tail = nullptr;
        size = 0;
    }
    int get(int index)
    {
        if (index >= size)
            return -1;
        int ri;
        Node* Temp = head;
        for (ri = 0; ri <= (index); ri++)
        {
            if (ri == 0)
                Temp = head;
            else
                Temp = Temp->Next;
        }
        return Temp->data;
    }
    void addAtHead(int val)
    {
        if (IsEmpty())
        {
            tail = head = new Node(val);
        }
        else
        {
            Node* Temp = head;
            head = new Node(val);
            head->Next = Temp;
        }
        size++;
    }
    void addAtTail(int val)
    {
        if (IsEmpty())
        {
            tail = head = new Node(val);
        }
        else
        {
            Node* Temp = tail;
            tail = new Node(val);
            Temp->Next = tail;
        }
        size++;
    }
    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index == 0)
        {
            addAtHead(val);

            return;
        }
        else if (index == size)
        {
            addAtTail(val);

            return;

        }
        size++;

        Node* Temp = head;
        Node* Previous = head;
        Node* After = head->Next;
        Node* Addres = new Node(val);
        int ri;
        for (ri = 0; ri < (index + 1); ri++)
        {
            if (ri == 0)
            {
                Temp = head;
                After = head->Next;
            }
            else
            {
                Previous = Temp;
                Temp = Temp->Next;
                After = Temp->Next;
            }
        }
        Previous->Next = Addres;
        Addres->Next = Temp;
    }
    void deleteAtIndex(int index)
    {
        if (IsEmpty())
            return;
        if (index >= size)
            return;

        if (index == 0)
        {
            head = head->Next;
            size--;
            return;
        }
        Node* Temp = head;
        Node* After = head->Next;
        Node* Previous = head;
        int ri;
        for (ri = 0; ri < (index + 1); ri++)
        {
            if (ri == 0)
            {
                Temp = head;
                After = head->Next;
            }
            else
            {
                Previous = Temp;
                Temp = Temp->Next;
                if (Temp->Next == nullptr)
                {

                    Previous->Next = nullptr;
                    tail = Previous;
                    size--;

                    return;
                }
                if (Temp == nullptr)
                {
                    After = Temp;
                }
                else
                {
                    After = Temp->Next;
                }
            }
        }
        if (index == size - 1)
        {
            tail = Previous;
            tail->Next = nullptr;

        }
        else
        {
            Previous->Next = After;

        }
        size--;

    }
    friend ostream& operator<<(ostream&, MyLinkedList T)
    {
        for (Node* Temp = T.head; Temp != nullptr; Temp = Temp->Next)
        {
            cout << Temp->data << " ";

        }
        cout << endl;
        return cout;

    }
};
int main()
{

    MyLinkedList T;
    T.addAtHead(1);
    cout << T;


    T.addAtTail(3);
    cout << T;

    T.addAtIndex(1, 2);
    cout << T;

    cout << T.get(1);
    cout << endl;


    T.deleteAtIndex(1);
    cout << T;


    cout << T.get(1);
    cout << endl;
    cout << T.get(3);
    cout << endl;
    T.deleteAtIndex(3);
    cout << T;

    T.deleteAtIndex(0);
    cout << T;


    cout << T.get(0);
    cout << endl;



    T.deleteAtIndex(0);
    cout << endl;


    cout << T.get(0);
    cout << endl;



}