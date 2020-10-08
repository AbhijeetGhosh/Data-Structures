#include <iostream>
#define SIZE 5   /* Size of Circular Queue */

//brah stop using work as an escape and face your emotions, this is not healthy ;_;
//no bro that's not how it works snap outta your delusions you aint no billionare 
//Delight in what u fear

using namespace std;

class CQueue {
private:
    int items[SIZE], front, rear;

public:
    CQueue(){
        front = -1;
        rear = -1;
    }
    void enQueue(int element)
    {

        if(front == 0 && rear == SIZE - 1)
            {
            cout<<"Queue is full"<<endl;
            return;
            }
        if(front == rear + 1)
            {
            cout<<"Queue is full"<<endl;
            return;
            }

        if(front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cout << endl << "Inserted " << element << endl;

    }

    void deQueue()
    {
        if(front == -1)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }

            cout<<"deleted element is"<<items[front]<<endl;
            if(front == rear)
                {
                front = -1
                
                rear = -1;
                } /* Q has only one element, so we reset the queue after deleting it. */
            else
                {
                front=(front+1) % SIZE;
                }


    }

    void display()
    {
        /* Function to display status of Circular Queue */
        int i;
         if(front == -1)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }

            cout <<"Items -> "<<endl;
            for(i=front; i!=rear;i=(i+1)%SIZE)
            {
                cout << items[i]<<endl;
            }
            cout << items[i]<<endl;//this is done because the last element in the loop will not be printed
            //and so we are printing it separately
            cout << "Front -> "<< front<<endl;
            cout <<"Rear -> " << rear<<endl;

    }

};


int main()
{
    CQueue q;

    // Fails because front = -1
    q.deQueue();

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    // Fails to enqueue because front == 0 && rear == SIZE - 1
    q.enQueue(6);

    q.display();

    q.deQueue();

    q.display();

    // Fails to enqueue because front == rear + 1
    q.enQueue(8);

    q.display();

    return 0;
}
