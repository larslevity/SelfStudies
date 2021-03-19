#include <iostream>
#include <random>

using namespace std;

bool inRange(int low, int high, int x) { return ((x - high) * (x - low) <= 0); }

int main() {
  random_device rd; // Will be used to obtain a seed for the random number
                    // engine
  mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  uniform_int_distribution<> distrib(0, 99);

  const int kRandVal = distrib(gen);
  int user_input = 0;
  int status = 0;

  cout << "Please guess a number between 0 and 99.\n";

  for (int i = 0;; i++) {
    cin >> user_input;
    if (cin.fail()) {
      cerr << "Error encountered, exiting...\n";
      status = 1;
      break;
    } else if (!inRange(0, 99, user_input)) {
      cerr << "[WARNING] : Number must be between 0 and 99\n";
    } else if (user_input < kRandVal) {
      cout << user_input << " is too small! Try again\n";
    } else if (user_input > kRandVal) {
      cout << user_input << " is too high! Try again\n";
    } else {
      cout << "Congratulations! You just beat the guessing machine!\n";
      break;
    }
  }

  cout << "The number to guess was " << kRandVal << endl;
  return status;
}