#include <iostream>
#include <sstream>
using namespace std;


int main(int argc, char* argv[]) {
    // Check the number of parameters
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " arg1 arg2" << endl;
        cerr << "Provide exactly TWO arguments!\n";
        return 1;
    }

    int number[2] = {0};
    string extension[2];

    for (int i = 0; i<2; i++) {
        stringstream filename{argv[i+1]};
        filename >> number[i] >> extension[i];
        cout << "Number, extension: " << number[i] << " , " << extension[i] << endl;
    }

    if (extension[0] == ".txt" && extension[1] == ".txt"){
        cout << (number[0]+number[1]) / 2 << endl;
    } else if (extension[0] == ".png" && extension[1] == ".png") {
        cout << number[0]+number[1] << endl;
    } else if (extension[0] == ".txt" && extension[1] == ".png") {
        cout << number[0] % number[1] << endl;
    } else {
        cerr << "Arguments must have the form: <INT>.[txt,png]\n";
        return 1;
    }

    return 0;
}

