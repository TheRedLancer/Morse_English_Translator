/*
 Name: Zach Burnaby
 Class: CPSC 122, Spring 2020
 Date: January 14, 2020
 Programming Assignment: PA1                                                                      
 Description: This program translates either Morse code to English or vice versa from a file, to a file.
*/
#include "MorseFunctions.h"

vector<string> createMorseStringList() {
    ifstream morseFile;
    morseFile.open("MorseStrings.tsv");
    testInputFile(morseFile);
    vector<string> morseStringsList;
    morseStringsList.resize(91);
    for (int i = 48; i < 58; i++) {
        morseFile >> morseStringsList.at(i);
    }
    for (int i = 65; i < 91; i++) {
        morseFile >> morseStringsList.at(i);
    }
    morseFile.close();
    return morseStringsList;
}

string translateEnglishWords(istringstream& activeString, vector<string> morseStringList, int& charCount) {
    string outputString;
    do {
        string engWord;
        getline(activeString, engWord, ' ');
        for (char k : engWord) {
            int engNumLetter = int(k);
            if (engNumLetter > 90) {
                engNumLetter -= 32;
            }
            outputString += morseStringList.at(engNumLetter) + ' ';
            charCount++;
        }
        if (activeString.good()) {
            outputString += ' ';
            charCount++;
        }
    } while (activeString.good());
    outputString.pop_back();
    return outputString;
}

string translateMorseLetters(istringstream& activeString, vector<string> morseStringList, int& charCount) {
    string outputString;
    do {
        string morseLetter;
        getline(activeString, morseLetter, ' ');
        int j = distance(morseStringList.begin(), find(morseStringList.begin()+ASCIIBEGIN, morseStringList.end(), morseLetter));
        if (j == ASCIIBEGIN) {
            outputString += ' ';
        } else {
            outputString += char(j);
        }
        charCount++;
    } while (activeString.good());
    return outputString;
}

string translateLine(istringstream& activeString, vector<string> morseStringList, bool direction, int& charCount) {
    string outputString = "";
    if (direction) {
        outputString = translateMorseLetters(activeString, morseStringList, charCount);
    } else {
        outputString = translateEnglishWords(activeString, morseStringList, charCount);
    } 
    outputString += char(10);
    return outputString;
}

void translateTo_FromMorse(ifstream& inputFile, ofstream& outputFile, vector<string> morseStringList, bool direction) {
    int charCount = 0;
    vector<string> textLinesVec = tokenizeFileLines(inputFile, charCount);
    for (int i = 0; i < textLinesVec.size(); i++) {
        istringstream activeString;
        activeString.clear();
        activeString.str(textLinesVec.at(i));
        textLinesVec.at(i).push_back(' ');
        outputFile << translateLine(activeString, morseStringList, direction, charCount);
    }
    reportConvertedChar(charCount);
}

vector<string> tokenizeFileLines(ifstream& inputFile, int& charCount) {
    vector<string> textLinesVec;
    string currentLine;
    while (!inputFile.eof()) {
        getline(inputFile, currentLine);
        if (inputFile.good()) {
            textLinesVec.push_back(currentLine);
            charCount++;
        }
    }
    return textLinesVec;
}

void reportConvertedChar(int charCount) {
    cout << endl << "Total characters converted successfully (including newline and white spaces): " << charCount << endl;
}

bool convoType(string& inputConvo) {
    while (inputConvo != "-t" && inputConvo != "-m") {
        cout << "Please enter a valid conversation option ('-m' or '-t'):";
        cin >> inputConvo;
    }
    if (inputConvo == "-t") {
        return 1;
    } else {
        return 0;
    }
}