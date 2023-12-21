#include <iostream>
#include <list>
#include <fstream>
#include <string>

using namespace std;

void convertAsciiIntToNumber(int& string);

int main()
{
    list<int> numbers;
    fstream myFile;
    myFile.open("../../../cool.txt", ios::in);

    if (myFile.is_open()) {
        //combine first and last digits to make a single 2 digit number, add them to a list and then combine the summed values
        //if there is only 1 digit, we just use the same digit twice
        string line;
        int firstNumber = 0;
        int lastNumber = 0;

        while (getline(myFile, line)) {

            //look for the first number in the line 
            for (char c : line) {
                if (c >= 48 && c <= 57) {
                    firstNumber = c;
                    break;
                }
            }

            //reverse line
            reverse(line.begin(), line.end());

            //look for the last number in the line, but its really the first here
            for (char c : line) {
                if (c >= 48 && c <= 57) {
                    lastNumber = c;
                    break;
                }
            }

            //convert ascii to number
            convertAsciiIntToNumber(firstNumber);
            convertAsciiIntToNumber(lastNumber);

            //convert to string
            string num1 = to_string(firstNumber);
            string num2 = to_string(lastNumber);

            //append 1st to 2nd
            num1 += num2;

            int outputValue = stoi(num1);

            //add to list
            numbers.push_back(outputValue);
        }
        myFile.close();
    }
    else {
        cout << "file has error";
    }

    //sum up all numbers
    int total = 0;
    for (int number : numbers) {
        total += number;
    }

    cout << "the total is: " << total << endl;
}

void convertAsciiIntToNumber(int& num) {
    //numbers being from 48 - 57 (48 = 0, 57 = 9)
    //take away 48, gives us the real int
    num -= 48;
}