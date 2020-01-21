/*
 Name: Zach Burnaby
 Class: CPSC 122, Spring 2020
 Date: January 14, 2020
 Programming Assignment: PA1                                                                      
 Description: This program translates either Morse code to English or vice versa from a file, to a file.
*/
#ifndef MORSE_FUNCTIONS_H
#define MORSE_FUNCTIONS_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream> // ifstream and ofstream
#include <vector>
#include <algorithm>

using namespace std;

const int ASCIIBEGIN = 47;

vector<string> createMorseStringList();
string translateLine(istringstream&, vector<string>, bool, int&);
string translateEnglishWords(istringstream&, vector<string> , int&);
string translateMorseLetters(istringstream&, vector<string>, int&);
vector<string> tokenizeFileLines(ifstream&, int&);
void reportConvertedChar(int);
bool convoType(string&);
void testInputFile(ifstream&);
void testOutputFile(ofstream&);
void translateTo_FromMorse(ifstream&, ofstream&, vector<string>, bool);

#endif