//============================================================================
// Name        : lab8.cpp
// Author      : Serafeim Papadias
// Description : comp2017 2017S
//============================================================================

// TODO 7: Include appropriate header
#include "utils.h"
#include "cafe.h"

int main() {

    // An array of Cafe which stores the information of all cafes.
    Cafe cafes[MAX_CAFE_NUM];

    // Count the number of cafes.
    int cafe_num = 0;
    // Variables for input
    char cafe_name[MAX_NAME_LENGTH];
    float x, y;
    float rating;
    int cafe_index, N;

    cout << "*********************CAFE RECOMMENDATION*********************" << endl;
    cout << "Please input your location" << endl;
    cout << "x y" << endl;
    // Read the information of you and initialize a Consumer.
    cin  >> x >> y;

    // Store the location to a point
    Point my_location = {x,y};

    // Variable for reading the choice
    int choice = 0;

    do {
        cout << "Please choose one of the following task:" << endl;
        cout << "0. Quit the program" << endl;
        cout << "1. Add a new cafe" << endl;
        cout << "2. Add a new rating" << endl;
        cout << "3. Change your location" << endl;
        cout << "4. Recommend w.r.t rating" << endl;
        cout << "5. Recommend w.r.t distance" << endl;
        cin >> choice;

        while (choice < 0 || choice > 5) {
            cout << "Your choice is invalid. Please input again!" << endl;
            cin  >> choice;
        }

        if (choice == 1) {
            cout << "Please input the information of the cafe." << endl;
            cout << "(name location)" << endl;
            cin  >> cafe_name >> x >> y;
            // Call the add_cafe
            Point temp_point = {x, y};
            add_cafe(cafes, cafe_num, cafe_name, temp_point);
        }

        if (choice == 2) {
            // Add a new rating
            while (true)
            {
                cout << "Please input the information of the cafe you want to rate." << endl;
                cout << "(cafe_index rating)" << endl;
                cin  >> cafe_index >> rating;
                if (rating >= 0 && rating <= 10)
                    break;
                else
                    cout << "The rating should be a number larger or equal to 0 and less than or equal to 10!" << endl;
            }
            // Call the add_rating
            add_rating(cafes, cafe_index, rating);
        }

        if (choice == 3) {
            cout << "Please input your location" << endl;
            cout << "x y" << endl;
            // Read the information of you and initialize a Consumer.
            cin >> x >> y;
            // Update my location
            my_location = {x,y};
        }

        if (choice == 4) {
            cout << "=== Recommendation Based on Rating ===" << endl;
            recommend_based_on_rating(cafes, cafe_num);
        }

        if (choice == 5) {
            cout << "=== Recommendation Based on Distance ===" << endl;
            cout << "Set the number of nearest neighbours N  " << endl;
            cin  >> N;
            recommend_based_on_distance(cafes, my_location, cafe_num, N);
        }

    } while (choice != 0);

    return 0;
}

