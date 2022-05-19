#include <iostream>
using namespace std;
class CircularQueue
{
private:
  int front;
  int rear;
  int size_of_arr = 5;
  int arr[5];
  int valcount=0;

public:
  CircularQueue()
  { front = -1;
    rear = -1;
    for (int i = 0; i < 5; i++)
    {
      arr[i] = 0;
    }
  }
  bool isEmpty()
  {
    if (front == -1 && rear == -1)
    {
      return true;
    }
    else
      return false;
  }
  bool isFull()
  {
    if ((rear+1)%size_of_arr == front)
    {
      return true;
    }
    else
      return false;
  }
  void Enqueue(int val)
  {
    if (isFull())
    {
      cout << "Queue is Full" << endl;
      return;
    }
    else if (isEmpty())
    {
      rear = 0;
      front = 0;
      arr[rear] = val;
      valcount++;
    }
    else
    {
      rear=((rear+1)%size_of_arr);
      arr[rear] = val;
      valcount++;
    }
  }
  int dequeue()
  {
    int x;
    if (isEmpty())
    {
      cout << "QUEUE IS EMPTY" << endl;
      x = 0;
    }
    else if (front == rear)
    {
      x = arr[front];
      arr[front] = 0;
      front = -1;
      rear = -1;
    }
    else
    {
      x = arr[front];
      arr[front] = 0;
      front=((front+1)%size_of_arr);
    }
    return x;
  }
  int count()
  {
    if (front == rear)
    {
      return 0;
    }
    else
    {
      return valcount;
    }
  }
  void display()
  {
    for (int i = 0; i < size_of_arr; i++)
    {
      cout << "  |  " << arr[i];
    }
    cout << "  |" << endl;
  }
};
int main()
{ CircularQueue q1;
  int option, value;
  
  do
  {
    cout << "\n\nWhat operation do you want to perform?Select Option number.Enter 0 to exit." << endl;
    cout << "1.Enqueue()" << endl;
    cout << "2.Dequeue()" << endl;
    cout << "3.1sEmpty()" << endl;
    cout << "4.isFull()" << endl;
    cout << "5.count()" << endl;
    cout << "6.display()" << endl;
    cout << "7.Clear Screen" << endl
         << endl;

    cin >> option;

    switch (option)
    {
    case 1:
      cout << "Enter The Value" << endl;
      cin >> value;
      q1.Enqueue(value);
      break;
    case 2:
      cout << "Dequeue Operation\nDequeued Value:" << q1.dequeue() << endl;
      break;
    case 3:
      if (q1.isEmpty())
        cout << "Queue is Empty" << endl;
      else
        cout << "Queue is not Empty" << endl;
      break;
    case 4:
      if (q1.isFull())
        cout << "Queue is Full" << endl;
      else
        cout << "Queue is not Full" << endl;
      break;
    case 5:
      cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
      break;
    case 6:
      cout << "Display Function Called - " << endl;
      q1.display();
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
  } while (option != 0);
  cout << "END OF PROGRAM";
  return 0;
}
