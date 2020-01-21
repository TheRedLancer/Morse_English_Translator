/*
 Name: Zach Burnaby
 Class: CPSC 122, Spring 2020
 Date: January 14, 2020
 Programming Assignment: PA1                                                                      
 Description: This program translates either Morse code to English or vice versa from a file, to a file.
*/

#include "MorseFunctions.h"

int main() {
    string convoInput, userInput, userOutput;
    
    cout << "Welcome to the best Morse/English translator!" << endl
         << "Please use '-m' to convert English to Morse Code or '-t' to convert from Morse Code to English" << endl
         << "Provide files in the following format:  '-m input.txt output.txt'" << endl;
    
    cin >> convoInput;
    cin >> userInput;
    cin >> userOutput;

    vector<string> morseStringList = createMorseStringList();

    ifstream inputFile;
    ofstream outputFile;


    inputFile.open(userInput);
    outputFile.open(userOutput);

    testInputFile(inputFile);
    testOutputFile(outputFile);

    bool direction = convoType(convoInput);

    translateTo_FromMorse(inputFile, outputFile, morseStringList, direction);

    inputFile.close();
    outputFile.close();

    return 0;
}
