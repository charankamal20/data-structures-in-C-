#include<iostream>
#include<vector>
#include<caca_conio.h>

class tasks	{
	private:
		int priority;
		char value;	

	public:
		void insert(char value);
	
};

void tasks::insert(char value)	{
	this->value = value;
	priority = int(value);
}

void heapify(std::vector<int> &heap, int size, int currentIndex)	{

}

void buildHeap(std::vector<int> &heap, int size)	{

}

int main()	{

	std::vector<tasks> heapArr;
	std::cout << "\nEnter a string to create a priority queue: ";
	char choice = '\0';
	while (true)	{
		choice = getch();
		if (choice != '\r' || choice != ' ')	{
			break;
		}
		heapArr.insert(choice);
	}



}