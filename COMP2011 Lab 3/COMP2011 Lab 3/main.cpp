//
//  main.cpp
//  COMP2011 Lab 3
//
//  Created by Chihim Ng on 24/9/2017.
//  Copyright © 2017 Chihim Ng. All rights reserved.
//

#include <iostream>
using namespace std;

int drawCandle(int height, int number, int padding) {
    for (int i = 0; i <= height; i++) {
        for (int k = 0; k < padding; k++) {
            cout << " ";
        }
        for (int j = 0; j < number; j++) {
            if (i == 0) {
                cout << " )";
            } else {
                cout << "()";
            }
        }
        for (int k = 0; k < padding; k++) {
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}

int drawCake(int layers, int height, int width, char crust, char filling) {
    for (int currentLayer = 0; currentLayer < layers; currentLayer++) {
        int layerInset = layers - 1 - currentLayer;
        for (int currentHeight = 0; currentHeight < height - layerInset * 1; currentHeight++) {
            for (int currentWidth = 0; currentWidth < width; currentWidth++) {
                if (currentWidth < layerInset * 2 || currentWidth >= width - layerInset * 2) {
                    cout << " ";
                } else if (currentWidth == layerInset * 2 || currentWidth == width - layerInset * 2 - 1) {
                    cout << crust;
                } else {
                    if (currentHeight == 0 || currentHeight == height - layerInset * 1 - 1) {
                        cout << crust;
                    } else {
                        cout << filling;
                    }
                }
            }
            cout << "\n";
        }
    }
 /* Alternative
    // Each Layer
    for (int myLayer = layers; myLayer > 0; myLayer--) {
        int layerDiff = myLayer - 1;
        // Each Row
        for (int myRow = 0; myRow < height - layerDiff * 1; myRow++) {
            // Each Column
            for (int myCol = 0; myCol < width; myCol++) {
                if (myCol < layerDiff * 2 || myCol > width - layerDiff * 2 - 1) {
                    // inset
                    cout << ' ';
                } else if (myCol == layerDiff * 2 || myCol == width - layerDiff * 2 - 1) {
                    // border
                    cout << crust;
                } else {
                    // middle
                    if (myRow == 0 || myRow == height - layerDiff * 1 - 1) {
                        //crust
                        cout << crust;
                    } else {
                        cout << filling;
                    }
                }
            }
            cout << '\n';
        }
    }
     */
    return 0;
}


int main(int argc, const char * argv[]) {
    int option = -1;
    bool exit = false;
    while (!exit) {
        while (!(option >= 0 && option <=3)) {
            cout << "1: Draw candles.\n";
            cout << "2: Draw cakes with rectangle shape.\n";
            cout << "3: Draw birthday cake with candles on it.\n";
            cout << "0: Exit.\n";
            cout << "Please input your selection: ";
            cin >> option;
        }
        switch (option) {
            case 0: { // exit
                exit = true;
                break;
            }
            case 1: { // draw candles
                int height;
                int number;
                cout << "Please input the height of the candle: ";
                cin >> height;
                cout << "Please input the number of the candle: ";
                cin >> number;
                drawCandle(height, number, 0);
                option = -1;
                break;
            }
            case 2: { // draw cake
                int layers;
                int height;
                int width = -1;
                char crust;
                char filling;
                bool isHeightWidthValid = false;
                while (!isHeightWidthValid) {
                    cout << "Please input the layers of the cake: ";
                    cin >> layers;
                    cout << "Please input the height of the bottom layer of the cake: ";
                    cin >> height;
                    while (width % 2) {
                        cout << "Please input the width of the bottom layer of the cake (which should be an even number): ";
                        cin >> width;
                    }
                    cout << "Please input the symbol for the crust of the cake: ";
                    cin >> crust;
                    cout << "Please input the symbol for the filling of the cake: ";
                    cin >> filling;
                    // validate heigh width input
                    int topLayerWidth = width - (layers * 4);
                    int topLayerHeight = height - (layers * 1);
                    if (topLayerWidth <= 4 || topLayerHeight <= 3) {
                        cout << "Height or width is not large enough. Please try again.\n";
                        width = -1;
                        isHeightWidthValid = false;
                    } else {
                        isHeightWidthValid = true;
                    }
                }
                drawCake(layers, height, width, crust, filling);
                option = -1;
                break;
            }
            case 3: { // draw both
                int candleHeight;
                int candleNumber;
                int cakeLayer;
                int cakeHeight;
                int cakeWidth = -1;
                char crust;
                char filling;
                bool isHeightWidthValid = false;
                while (!isHeightWidthValid) {
                    cout << "Please input the height of the candle: ";
                    cin >> candleHeight;
                    cout << "Please input the number of the candle: ";
                    cin >> candleNumber;
                    cout << "Please input the layers of the cake: ";
                    cin >> cakeLayer;
                    cout << "Please input the height of the bottom layer of the cake: ";
                    cin >> cakeHeight;
                    while (cakeWidth % 2) {
                        cout << "Please input the width of the bottom layer of the cake (which should be an even number): ";
                        cin >> cakeWidth;
                    }
                    cout << "Please input the symbol for the crust of the cake: ";
                    cin >> crust;
                    cout << "Please input the symbol for the filling of the cake: ";
                    cin >> filling;
                    // validate heigh width input
                    int topLayerWidth = cakeWidth - (cakeLayer * 4);
                    int topLayerHeight = cakeHeight - (cakeLayer * 1);
                    if (topLayerWidth <= 4 || topLayerHeight <= 3 || topLayerWidth < candleNumber) {
                        cout << "Height or width is not large enough. Please try again.\n";
                        cakeWidth = -1;
                        isHeightWidthValid = false;
                    } else {
                        isHeightWidthValid = true;
                    }
                }
                drawCandle(candleHeight, candleNumber, cakeLayer * 2);
                drawCake(cakeLayer, cakeHeight, cakeWidth, crust, filling);
                option = -1;
                break;
            }
            default: {
                option = -1;
                break;
            }
        }
    }
    
    return 0;
}

