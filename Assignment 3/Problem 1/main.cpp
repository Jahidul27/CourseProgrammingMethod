//Jahidul Islam
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class DaryHeap
{
private:
    int d;
    int nowSize;
    int size;
    int *array;
public:


    DaryHeap(int cap, int d)
    {
        nowSize = 0;
        size = cap + 1;
        array = new int[cap + 1];
        for (int i = 0 ; i < cap + 1; i++)
            array[i] = -1;
    }



      //This will fill up the heap with a array you provide

    DaryHeap(int* array, int d)
    {
        int i = 0;
        while (array[i] != -1)
            i++;
        nowSize = i;
        this->array = array;
        this->d = d;
        buildHeap();
    }

    bool isEmpty()
    {
        return nowSize == 0;
    }
    bool isFull()
    {
        return nowSize == size;
    }
    int parent(int i)
    {
        return (i - 1) / d;
    }
    int kthChild(int i, int k)
    {
        return d * i + k;
    }




     // This is a function to allow you to insert an element

    void insert(int k)
    {
        if (isFull())
        {
            cout<<"Array Out of Bounds"<<endl;
            return;
        }
        int hole = nowSize;
        nowSize++;
        array[hole] = k;
        swim(hole);
    }





     // This function will allow you to delete an element at a given index so it can be max if you choose
    int delMax(int hole)
    {
        if (isEmpty())
        {
            cout<<"Array Underflow"<<endl;
            return 0;
        }
        int keyItem = array[hole];
        array[hole] = array[nowSize - 1];
        nowSize--;
        sink( hole );
        return keyItem;
    }




     // This will build the actual heap
    void buildHeap()
    {
        for (int i = nowSize - 1 ; i >= 0; i--)
            sink(i);
    }




     // sink

    void sink(int hole)
    {
        int child;
        int tmp = array[hole];
        for ( ; kthChild(hole, 1) < nowSize; hole = child)
        {
            child = smallestChild( hole );
            if (array[child] < tmp)
                array[hole] = array[child];
            else
                break;
        }
        array[hole] = tmp;
    }
    int smallestChild(int hole)
    {
        int bestChildYet = kthChild(hole, 1);
        int k = 2;
        int candidateChild = kthChild(hole, k);
        while ((k <= d) && (candidateChild < nowSize))
        {
            if (array[candidateChild] < array[bestChildYet])
                bestChildYet = candidateChild;
            k++;
            candidateChild = kthChild(hole, k);
        }
        return bestChildYet;
    }





     // swim

    void swim(int hole)
    {
        int tmp = array[hole];
        for (; hole > 0 && tmp < array[parent(hole)]; hole = parent(hole))
            array[hole] = array[ parent(hole) ];
        array[hole] = tmp;
    }





    //This will print the heap

    void printHeap()
    {
        cout<<"\nHeap = ";
        for (int i = 0; i < nowSize; i++)
            cout<<array[i]<<"   ";
        cout<<endl;
    }
};





 // Main

int main()
{
    cout<<"This wiil begin the Dary Heap Test\n\n";
    cout<<"Enter the size you wish and the D of Dary Heap: ";
    int size, num, choice, val;
    cin>>size>>num;
    DaryHeap th(size, num);
    char ch;
    do
    {
        cout<<"\nThese are the options you can select to proceed with program\n";
        cout<<"1. Insert "<<endl;
        cout<<"2. Delete a specified position"<<endl;
        bool chk;
        cout<<"Choose the number you wish to perform: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Enter integer element for what you want to insert into heap: ";
                cin>>val;
                th.insert(val);
                break;
            case 2:
                cout<<"Enter the position of the element you want to delete: ";
                cin>>val;
                th.delMax(val - 1);
                break;

            default :
                cout<<"Try again as this was not a valid input \n ";
                break;
        }
        th.printHeap();
        cout<<"\nIf you want to keep processing (Type y or n) for yes or no \n";
        cin>>ch;
    }
    while (ch == 'Y'|| ch == 'y');
    return 0;
}























//Below is a separate implementation of HeapSort


//using namespace std;

//void heapify(int arr[], int n, int i)
//{
//    int largest = i; // Initialize largest as root
//    int l = 2*i + 1; // left = 2*i + 1
//    int r = 2*i + 2; // right = 2*i + 2
//
//    if (l < n && arr[l] > arr[largest])
//        largest = l;
//
//    if (r < n && arr[r] > arr[largest])
//        largest = r;
//
//    if (largest != i)
//    {
//        swap(arr[i], arr[largest]);
//
//        heapify(arr, n, largest);
//    }
//}
//
//
//void heapSort(int arr[], int n)
//{
//    for (int i = n / 2 - 1; i >= 0; i--)
//        heapify(arr, n, i);
//
//    for (int i=n-1; i>=0; i--)
//    {
//        swap(arr[0], arr[i]);
//
//        heapify(arr, i, 0);
//    }
//}
//
//
//void printArray(int arr[], int n)
//{
//    for (int i=0; i<n; ++i)
//        cout << arr[i] << " ";
//    cout << "\n";
//}