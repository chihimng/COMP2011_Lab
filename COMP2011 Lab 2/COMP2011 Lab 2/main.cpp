//
//  main.cpp
//  COMP2011 Lab 2
//
//  Created by Chihim Ng on 18/9/2017.
//  Copyright © 2017 Chihim Ng. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    float exit = false;
    
    while (!exit) {
        int totalIncome = -1;
        int isMarried = -1;
        int numOfchildren = -1;
        float childrenAllowance;
        int claimedDeduction = -1;
        float netChargable;
        float totalTax = 0;
        string wantToRepeat = "";
        // header
        cout << "===========================\nAn imaginary tax calculator\n===========================\n";
        
        // Q1 Total income
        cout << "1. Total income?\n";
        while (totalIncome < 0) {
            cin >> totalIncome;
            cout << (totalIncome < 0 ? "Invalid input, please enter again.\n" : "\n");
        }
        
        // Q2 Marial Status
        cout << "2. Marital Status?\nInput 0 for single/widowed, 1 for married.\n";
        while (isMarried < 0 || isMarried > 1) {
            cin >> isMarried;
            cout << ((isMarried < 0 || isMarried > 1) ? "Invalid input, please enter again.\n" : "\n");
        }
        
        // Q3 Number of dependent kids
        cout << "3. Number of dependent kids?\n";
        while (numOfchildren < 0) {
            cin >> numOfchildren;
            cout << (numOfchildren < 0 ? "Invalid input, please enter again.\n" : "\n");
        }
        
        // Children Allowance calculation
        childrenAllowance = numOfchildren * (isMarried == 0 ? 4000 : 3000);
        
        // Q4 Amount of other tax deduction to be claimed
        cout << "4. Amount of other tax deduction to be claimed?\n";
        while (claimedDeduction < 0) {
            cin >> claimedDeduction;
            cout << (claimedDeduction < 0 ? "Invalid input, please enter again.\n" : "\n");
        }
        
        // Tax calculation
        netChargable = totalIncome - childrenAllowance - claimedDeduction;
        if (netChargable > 0) {
            totalTax += (netChargable >= 45000 ? 45000 : netChargable) * 0.02;
            netChargable -= 45000;
        }
        if (netChargable > 0) {
            totalTax += (netChargable >= 45000 ? 45000 : netChargable) * 0.07;
            netChargable -= 45000;
        }
        if (netChargable > 0) {
            totalTax += netChargable * 0.12;
            netChargable = 0;
        }
        cout << "You need to pay $" << totalTax << " tax.\n\n";
        
        // Ask if repeat program
        cout << "Do you want to calculate another tax?\ny for YES, n for no.\n";
        while (!(wantToRepeat == "y" || wantToRepeat == "n")) {
            cin >> wantToRepeat;
            cout << (!(wantToRepeat == "y" || wantToRepeat == "n") ? "Invalid input, please enter again.\n" : "\n");
        }
        exit = (wantToRepeat == "n");
    }
    
    return 0;
}
