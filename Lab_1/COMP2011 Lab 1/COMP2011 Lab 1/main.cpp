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
    string monthDict[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string adjectives[] = {"intelligent", "beautiful", "sweet", "adventurous", "passionate", "reliable", "humble", "ecletic", "brave", "smart", "easygoing", "helpful"
    };
    bool finish = false;
    while (!finish) {
        cout << "Which month were you born in?\n";
        cin >> month;
        switch (month) {
            case 1 ... 12 : cout << "I see! You were born in " + monthDict[month - 1] + ". You must be " + adjectives[month - 1] + "!\n";
                break;
            default: cout << "Oh. You must be... crazy! Bye!\n";
                finish = true;
                break;
        }
    }
    return 0;
}
