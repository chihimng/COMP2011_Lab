//
//  main.cpp
//  COMP2011 Lab 7
//
//  Created by Chihim Ng on 1/11/2017.
//  Copyright © 2017 Chihim Ng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

void copyStr(char from[], char to[]) {
    int i = 0;
    while (!(from[i] == '\0')) {
        to[i] = from[i];
        i += 1;
    }
    to[i] = '\0';
}

void appendStr(char target[], const char content[]) {
    int i = 0;
    int j = 0;
    while (!(target[i] == '\0')) {
        i += 1;
    }
    while (!(content[j] == '\0')) {
        target[i] = content[j];
        i += 1;
        j += 1;
    }
    target[i] = '\0';
}


int main(int argc, const char * argv[]) {
    const int MaxSize = 1000;
    int wordCount = 0;
    int charCount = 0;
    char rawString[MaxSize*MaxSize] = {};
    char words[MaxSize][MaxSize] = {};
    char punctuations[15] = {'\'',',','.','-','_','<','>','(',')','!','\?','\\','\"',';',':'};
    char filename[MaxSize];

    cout << "Input file name:" << endl;
    cin >> filename;
    
    char inputFileName[MaxSize] = {};
    copyStr(filename, inputFileName);
    appendStr(inputFileName, ".txt");
    ifstream ifs;
    ifs.open(inputFileName);
    if (!ifs) {
        cout << "Failed to open " << inputFileName << endl;
        return -1;
    }
    
    while (!ifs.eof() && !(charCount >= MaxSize*MaxSize)) {
        ifs.get(rawString[charCount]);
        charCount += 1;
    }
    ifs.close();
    
    for (int i = 0; i < charCount; i++) {
        for (int j = 0; j < 15; j++) {
            if (rawString[i] == punctuations[j] || rawString[i] == '\n') {
                rawString[i] = ' ';
            } else if (rawString[i] >= 'A' && rawString[i] <= 'Z') {
                rawString[i] = rawString[i] + 'a' - 'A';
            }
        }
    }
    
    int wordLength = 0;
    for (int i = 0; i < charCount; i++) {
        if (rawString[i] == ' ') {
            if (i > 0 && rawString[i-1] != ' ') {
                wordLength = 0;
                wordCount += 1;
            }
            continue;
        }
        words[wordCount][wordLength] = rawString[i];
        wordLength += 1;
    }
    char outputFileName[MaxSize] = {};
    copyStr(filename, outputFileName);
    appendStr(outputFileName, "_lower.txt");
    ofstream ofs;
    ofs.open(outputFileName);
    if (!ofs) {
        cout << "Failed to open " << outputFileName << endl;
        return -1;
    }
    ofs << "text size : " << wordCount << endl;
    for (int i = 0; i < wordCount; i++) {
        ofs << words[i] << endl;
    }
    ofs.close();
    
    return 0;
}
