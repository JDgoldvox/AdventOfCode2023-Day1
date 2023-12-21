#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

void convertAsciiIntToNumber(int& string);
void CreateWordMap();
bool isBeginningOfWord(string s);
int stringToInt(string s);

//unordered_map of char -> char - > string
unordered_map<char, unordered_map<char, string>> words;

int main()
{
    //creates a word map mapping the first two letters to the full string
    CreateWordMap();

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
            
            firstNumber = 0;
            lastNumber = 0;

            //look for the first number in the line 
            cout << "----------------------" << endl;
            string twoLetters = "";
            string currentWord = "";
            string target = "";
            int nextLetterPosition = 0;

            for (char c : line) {
                cout << c << endl;
                //if its a number
                if (c >= 48 && c <= 57) {
                    if (firstNumber == 0) {
                        firstNumber = c;
                    }
                    lastNumber = c;

                    currentWord.erase();
                }

                //if its a letter
                if (c >= 97 && c <= 122) {
                    //we going to try to collect the first two letters
                    //add new char
                    twoLetters += c;

                    if (twoLetters.length() < 2) {
                        continue;
                    }

                    //if the next letter is not part of our previous word
                    if (target[nextLetterPosition] != c) {
                        currentWord.erase();
                    }

                    //check if we have a word
                    if (isBeginningOfWord(twoLetters) && currentWord.length() == 0) { //happens once
                        //cout << "found the beginning of a word!" << endl;
                        //add initial word
                        currentWord += twoLetters;
                        target = words[twoLetters[0]][twoLetters[1]];
                        nextLetterPosition = 2;
                    }
                    if (target[nextLetterPosition] == c) {
                        //if the next letter we need is equal to the letter we have, add it to our current word
                        currentWord += c;
                        nextLetterPosition++;

                        if (currentWord == target) {
                            //return the real number
                            //if the first number is not set, set it
                            if (firstNumber == 0) {
                                firstNumber = stringToInt(currentWord);
                            }
                            //set last number
                            lastNumber = stringToInt(currentWord);
                        }
                    }

                    //chop off oldest char
                    twoLetters.erase(0, 1);
                }
            }

            //convert ascii to number
            convertAsciiIntToNumber(firstNumber);
            convertAsciiIntToNumber(lastNumber);

            //convert to string
            string num1 = to_string(firstNumber);
            string num2 = to_string(lastNumber);

            cout << "first = " << num1 << endl;
            cout << "last = " << num2 << endl;

            //append 1st to 2nd
            num1 += num2;

            int outputValue = stoi(num1);

            //add to list
            numbers.push_back(outputValue);

            firstNumber = 0;
            lastNumber = 0;
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
    if (num <= 9) {
        //if its already converted dont do anything
        return;
    }

    num -= 48;
}

bool isBeginningOfWord(string s) {
    //one, two, three, four, five, six, seven, eight, and nine

    if (s == "on") return true;
    else if (s == "tw") return true;
    else if (s == "th") return true;
    else if (s == "fo") return true;
    else if (s == "fi") return true;
    else if (s == "si") return true;
    else if (s == "se") return true;
    else if (s == "ei")  return true;
    else if (s == "ni") return true;
    else return false;
}

int stringToInt(string s) {
    //one, two, three, four, five, six, seven, eight, and nine
    if (s == "one") return 1;
    else if (s == "two") return 2;
    else if (s == "three") return 3;
    else if (s == "four")  return 4;
    else if (s == "five") return 5;
    else if (s == "six") return 6;
    else if (s == "seven") return 7;
    else if (s == "eight")  return 8;
    else if (s == "nine") return 9;
    else {
        cout << "we should never be here in string to int, number doesn't exist" << endl;
    }
}

void CreateWordMap() {
    words['o']['n'] = "one";
    words['t']['w'] = "two";
    words['t']['h'] = "three";
    words['f']['o'] = "four";
    words['f']['i'] = "five";
    words['s']['i'] = "six";
    words['s']['e'] = "seven";
    words['e']['i'] = "eight";
    words['n']['i'] = "nine";
}