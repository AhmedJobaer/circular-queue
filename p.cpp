# include <iostream>

using namespace std;

# define SIZE 10

int A[SIZE];

// Initially Queue is empty
int front = -1;
int rear = -1;

bool isempty();
void enqueue(int value);
void dequeue();
void displayQueue();

//Main Function
int main()
{
    int choice, value;
    while (true)
    {
        //system("clear");
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "please enter the number of your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            cout << endl;
            enqueue(value);
            break;
        case 2:
            cout << endl;
            dequeue();
            break;
        case 3:
            cout << endl << "The queue is: ";
            displayQueue();
            break;
        }
        cout << endl << endl;
        //system("read -p 'Press Enter to continue...' var");
    }
    return 0;
}
//Function to check if queue is empty or not
bool isempty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}
//function to enter elements in queue
void enqueue(int value)
{
//if the queue is full
    if ((rear + 1) % SIZE == front)
        cout << "Queue is full " << endl;

    else
    {
//in case the queue is empty
        if (front == -1)
            front = 0;
//if queue had previous elements
        rear = (rear + 1) % SIZE;
        A[rear] = value;
        cout << "The element " << value << " has been added to the queue successfully!" << endl;
        displayQueue();
        cout << endl;
    }
}
//function to delete/remove element from queue
void dequeue()
{
    int x;
    if (isempty())
        cout << "Queue is empty" <<endl;
    else
    {
        x = A[front];
//only one element left in the queue
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
        cout << "The element " << x << " has been dequeued successfully!" << endl;
        displayQueue();
    }
}

//function to Display queue
void displayQueue()
{
    if(isempty())
        cout << "Queue is empty" <<endl;
    else
    {
        cout << "The current queue is: ";
        int i;
        if(front <= rear)
        {
            for(i = front; i <= rear; i++)
            {
                cout << A[i] << " ";
            }
        }
        else
        {
            i = front;
            while(i < SIZE)
            {
                cout << A[i] <<" ";
                i++;
            }
            i = 0;
            while(i <= rear)
            {
                cout << A[i] <<" ";
                i++;
            }
        }
    }
}

