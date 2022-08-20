#include<iostream>

using namespace std;

# define N 5
int queue[N];
int front = -1;
int rear = -1;

//function prototype
void enqueue(int);
void dequeue();
void display();
void peek();

int main()
{
    /*enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();*/
    while(true)
    {
        int c, num;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. See front element" << endl;
        cout << "4. Display Queue" << endl;
        cout << "Please enter the number: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter value: ";
            cin >> num;
            cout << endl;
            enqueue(num);
            break;
        case 2:
            cout << endl;
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        }
        cout << endl;
        cout << endl;
    }

    return 0;
}


/*for Queue with linear array for enqueue function
1. if(rear == N-1) then it is full
2. else if(front == -1 && rear == -1) then it is empty
3. else rear++ then print rear
*/


void enqueue(int x)
{

    if(front == -1 && rear == -1) //Queue is empty
    {
        front = rear = 0;
        queue[rear] = x;
        display();
    }
    else if((rear + 1) % N == front) // for circular array
    {
        cout << "Overflow!!!Queue is full" << endl;
    }
    else
    {
        rear = (rear + 1) % N; // when rear is the last elements
        queue[rear] = x;
        display();
    }
}


/*for Queue with linear array for enqueue function
1. if(front == -1 && rear == -1) for checking is empty or not.
2. else if(front == rear) then we set both equal to 1.
3. else we print front then front++
*/

void dequeue()
{
    if(front == -1 && rear == -1) // for checking queue is empty or not
    {
        cout << "Underflow!!!Queue is empty" <<endl;
    }
    else if(front == rear) // when front and rear is same
    {
        front = rear = -1;
    }
    else
    {
        cout << "The deleted item is: "<< queue[front] <<endl;
        front = (front + 1) % N; // when rear is the last elements
        display();
    }
}


/*for Queue with linear array for enqueue function
1. if(front == -1 && rear == -1) for checking is empty or not.
2. else we can use a for loop and print the queqe
*/


void display()
{
    int i = front;
    if(front == -1 && rear == -1)
    {
        cout << "Queue is empty!!!!!!!!!" <<endl;
    }
    else
    {
        cout<< "Queue is: ";
        while(i != rear)              // for circular array we modified the condition
        {
            cout << queue[i] << " ";
            i = (i + 1) % N;
        }
        cout << queue[rear] << " ";
    }
}

void peek()
{
    if(front == -1 && rear == -1)
    {
        cout << "Circular Queue is empty!!!!!!!!!" <<endl;
    }
    else
    {
        cout << "\nFront is: " << queue[front] <<endl;;
    }
}


