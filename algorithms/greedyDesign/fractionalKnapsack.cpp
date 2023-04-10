#include <iostream>
#include <vector>

float knapSackSize = 15.00;

typedef std::pair<float, float> Object; // wietght // profit

int partition(std::vector<Object> &objects, int start, int end) {
float pivot = (objects[end].first) / (objects[end].second); // pivot element
  int i = (start - 1);

  for (int j = start; j <= end - 1; j++) {
    // If current element is smaller than the pivot
    if ((objects[j].first / objects[j].second) < pivot) {
      i++; // increment index of smaller element
      Object t = objects[i];
      objects[i] = objects[j];
      objects[j] = t;
    }
  }
  Object t = objects[i + 1];
  objects[i + 1] = objects[end];
  objects[end] = t;
  return (i + 1);
}

void quick(std::vector<Object> &objects, int start, int end) /* a[] = array to
                       be sorted, start = Starting index, end = Ending index */
{
  if (start < end) {
    int p = partition(objects, start, end); // p is the partitioning index
    quick(objects, start, p - 1);
    quick(objects, p + 1, end);
  }
}

int knapsack(std::vector<Object> &objects) {
  quick(objects, 0, objects.size());
  int profit = 0;
  // for (int i = 0; i < objects.size(); i++) {
  //   std::cout << objects[i].first << "  " << objects[i].second << "\n";
  // }
  int i = 0;
  while (knapSackSize > 0 || objects.size() != 0) {
    if (knapSackSize - objects[i].first > 0) {
      knapSackSize -= objects[i].first;
      // continue;
      profit = profit + objects[i].second;
      i++;
    } else {
      objects[i].second = knapSackSize * (objects[i].second / objects[i].first);
      objects[i].first = knapSackSize;
      profit = profit + objects[i].second;
      
      knapSackSize -= objects[i].first;
      i++;
      break;
    }
    // getchar();
  }

  return profit;
}

int main(int argc, char *argv[]) {
  std::vector<Object> objects;
  objects.push_back(std::make_pair(1, 2));
  objects.push_back(std::make_pair(4, 18));
  objects.push_back(std::make_pair(7, 7));
  objects.push_back(std::make_pair(3, 8));
  objects.push_back(std::make_pair(4, 12));
  objects.push_back(std::make_pair(2, 5));
  objects.push_back(std::make_pair(6, 7));

  std::cout << "\nGREEDY DESIGN STRATEGY\n\n";
  std::cout << "Enter the knapsack capacity\n";
  std::cin >> knapSackSize;

  // for (int i = 0; i < objects.size(); i++) {
  //   std::cout << objects[i].first << "\t" << objects[i].second << "\n";
  // }
  int profit = knapsack(objects);
  std::cout << "Maximum Profit: " << profit << std::endl;

  return 0;
}
