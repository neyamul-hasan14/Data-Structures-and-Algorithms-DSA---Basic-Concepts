#include<iostream>
using namespace std;

const int cap=5;
struct queue
{
    int frnt, rear, sz=0;
    int arr[cap];

};
void enqueue(queue *q, int  val)
{
    if(q->sz==cap)
    {
        cout<< "The Queue is Full."<< endl;
    }
    else
    {
        q->rear= (q->rear+1)%cap;
        q->arr[q->rear]= val;
        q->sz++;
    }
}
void dequeue(queue *q)
{
    if(q->sz==0)
    {
        cout<< "The Queue is Empty!"<< endl;
    }
    else
    {
        cout<< q->arr[q->frnt]<< endl;
        q->frnt= (q->frnt +1)%cap;
        q->sz--;
    }
}
void peek(queue *q)
{
    if(q->sz == 0)
    {
        cout<< "The Queue is Empty!"<< endl;
    }
    else
    {
        cout<< q->arr[q->frnt]<< endl;
    }
}
void isEmpty(queue *q)
{
    if(q->sz == 0)
    {
        cout<< "The queue is Empty!"<< endl;
    }
    else
    {
        cout<< "The queue is not Empty."<< endl;
    }
}
void isFull(queue *q)
{
    if(q->sz == cap)
    {
        cout<< "The queue is Full!"<< endl;
    }
    else
    {
        cout<< "The queue is not Full."<< endl;
    }
}
void display(queue *q)
{
    if(q->sz == cap)
    {
        cout<< "The queue is Full!"<< endl;
    }
    else if(q->sz == 0)
    {
        cout<< "The Queue is Empty!"<< endl;
    }
    else
    {
        int x=q->frnt;
        for(int i=0; i<q->sz; i++)
        {
            cout<< q->arr[(x%cap)]<< endl;
            x++;
        }
    }
}

int main()
{
    queue *q1;
    q1 = new queue();

    q1->frnt= 0;
    q1->rear= -1;
    while (1)
    {
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n0. Exit" << endl;
        int x;
        cin >> x;
        if (x == 0)
            break;
        else if (x == 1)
        {
            cout << "Enter a value: ";
            int y;
            cin >> y;
            enqueue(q1, y);
        }
        else if (x == 2)
        {
            dequeue(q1);
        }
        else if (x == 3)
        {
            peek(q1);
        }
        else if (x == 4)
        {
            isEmpty(q1);
        }
        else if(x == 5)
        {
            isFull(q1);
        }
        else if (x == 6)
        {
            display(q1);
        }
    }
}
