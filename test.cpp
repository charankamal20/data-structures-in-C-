#include "iostream"
#include <unistd.h>

void dots(int seconds) {

  for (int i = 0; i < seconds; i++) {
    std::cout << ". ";
    sleep(1);
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  system("clear");
  sleep(3);
  std::cout << "Hey!\n";
  sleep(2);
  std::cout << "Watcha doing ^o^\n";
  dots(3);
  std::cout << "This is a reminder, i love your boobs <3<3<3<3";
  dots(3);
  std::cout << "I hope they miss me as much i miss dem ToT";
  dots(3);
  std::cout << "And I am crazy for your ass *o* <3";
  dots(3);
  std::cout << "And lastly, i wanna thank you for taking suchhhh good care of"
            << " them......................for me <3";
  dots(3);
  std::cout << "stay sexy momo\n";
  sleep(3);

  return 0;
}
