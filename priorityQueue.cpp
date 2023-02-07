#include<iostream>
#include<vector>


void heapify(std::vector<int> &heap, int size, int currentIndex)	{

    int largest = currentIndex;
    int leftChild = 2*currentIndex + 1;
    int rightChild = 2*currentIndex + 2;

    if (leftChild < size && heap[leftChild] > heap[largest])    
        largest = leftChild;
    if (rightChild < size && heap[rightChild] > heap[largest])
        largest = rightChild;
    
    if(currentIndex != largest) {
        std::swap(heap[currentIndex], heap[largest]);
        heapify(heap, size, largest);
    }
   
}


void buildHeap(std::vector<int> &heap, int size)	{
    for (int i = (size/2) - 1; i >= 0; i--) {
        heapify(heap, size, i);
    }
}

void deleteHighestPriority(std::vector<int> &heap)    {
    std::swap(heap[heap.size() - 1], heap[0]);
    heap.pop_back();
    buildHeap(heap, heap.size());
}

void insert(std::vector<int> &heap, int value)   {
    heap.push_back(value);
    buildHeap(heap, heap.size());
}

void printArray(std::vector<int> &heap)   {
    std::cout << std::endl;
    for (int i = 0; i < heap.size(); i++)   {
        std::cout << heap[i] << " " ;
    }
}

int peekHighestPriority(std::vector<int> &heap)  {
    return heap[0];
}

int main()	{

	std::vector<int> heapArr;
	std::cout << "\nEnter a string of numbers to create a priority queue: ";
    {
        std::string choice;
        std::cin >> choice;
        int i = 0;
        while (i < choice.length())	{
            heapArr.push_back(int(choice[i]) - 48);
            i++;
        }
    }
    
    buildHeap(heapArr, heapArr.size());
    printArray(heapArr);
    
    char choice;
    while (true)    {
        //system("clear");
        std::cout << "\nThese are the available operations: \n"
                  << "\n1. Peek Highest Priority element"
                  << "\n2. Delete Highest Priority element"
                  << "\n3. Insert Element"
                  << "\n4. Display Priority Queue"
                  << "\n5. Print heap array"
                  << "\n6. Exit"
                  << "\nYour Choice: ";


        std::cin >> choice;
        switch(choice)  {
            case '1':   {
                std::cout << peekHighestPriority(heapArr);
                break;
            }
            case '2':   {
                deleteHighestPriority(heapArr);
                break;
            }
            case '3':   {
                int value;
                std::cout << "\nEnter a number: ";
                std::cin >> value;
                insert(heapArr, value);
                break;
            }
            case '4':   {
                int size = heapArr.size();
                int tempArr[size];
                for (int i = 0; i < heapArr.size(); i++)    {
                    tempArr[i] = heapArr[i];
                }
                int i = 0;
                while (heapArr.size() > 0)  {
                    std::cout << heapArr[i] << " ";
                    deleteHighestPriority(heapArr);
                }
                for (i = 0; i < size; i++)  {
                    heapArr.push_back(tempArr[i]);
                }
                break;
            }
            case '5':   {
                printArray(heapArr);
                break;
            }
            case '6':   {
                exit(0);
            }
            default :   {
                break;
            } 
        }
    }
}