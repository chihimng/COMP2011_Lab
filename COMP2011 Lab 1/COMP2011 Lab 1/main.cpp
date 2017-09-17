//
//  main.cpp
//  COMP2011 Lab 1
//
//  Created by Chihim Ng on 11/9/2017.
//  Copyright © 2017 Chihim Ng. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int month;
    const string MONTH_DICT[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    const string ADJECTIVES[] = {"intelligent", "beautiful", "sweet", "adventurous", "passionate", "reliable", "humble", "ecletic", "brave", "smart", "easygoing", "helpful"
    };
    bool isFinished = false;
    while (!isFinished) {
        cout << "Which month were you born in?\n";
        cin >> month;
        if (month >= 1 && month <= 12) {
            cout << "I see! You were born in " + MONTH_DICT[month - 1] + ". You must be " + ADJECTIVES[month - 1] + "!\n";
        } else {
            cout << "Oh. You must be... crazy! Bye!\n";
            isFinished = true;
        }
    }
    return 0;
}
