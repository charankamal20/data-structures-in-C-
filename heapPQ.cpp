#include<iostream>

void swap(char *a, char* b) {
    char temp;
    *a = temp;
    *a = *b;
    *b = temp;
}

void heapify(char array[], int size, int i) {
	int largest = i;
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2
	// If left child is larger than root
	if (l < size && array[l] > array[largest])
		largest = l;
	// If right child is larger than largest so far
	if (r < size && array[r] > array[largest])
		largest = r;
	// If largest is not root
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, size, largest);
	}
}

void heapBuild(char array[], int size)   {
	int startIdx = (size / 2) - 1;
	for (int i = startIdx; i >= 0; i--)
	{
		heapify(array, size, i);
	}
}

int main()  {

    std::cin.clear();
    std::string data = "";
    std::cout << "Enter a data string: ";
    std::cin >> data;
    char *start = NULL;
    start = &data[0];
    heapBuild(start, data.length());
    std::cout << std::endl;
    for (int i = 0; i < data.length(); i++) {
        std::cout << data[i] << " ";
    }

}
