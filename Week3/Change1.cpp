#include <iostream>

int get_change(int change) {
  //write your code here
  int result = 0;
  result += change/10;
  change = change % 10;
  result += change/5;
  change = change % 5;
  change = change + result;
  return change;
}

int main() {
  int change;
  std::cin >> change;
  std::cout << get_change(change) << '\n';
}