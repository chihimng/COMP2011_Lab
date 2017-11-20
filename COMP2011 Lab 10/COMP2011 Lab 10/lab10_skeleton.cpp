#include "lab10.h"
#include "frame.h"

using namespace std;

void copyImageData(char from[ROWS][COLS], char to[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            to[i][j] = from[i][j];
        }
    }
}

// TODO 1
// 
// Create frame linked list containing all frames and copy image from imageData to every frame.
// 
// imageData:	3D char array where images of each frame are stored
// numOfFrames:	Number of frames in total
// 
// return:		Pointer to the head of linked list
// 
Frame *createFrameLinkedList(char imageData[][ROWS][COLS], int numOfFrames)
{
	Frame *result = nullptr;
    Frame *last = nullptr;
    for (int i = 0; i < numOfFrames; i++) {
        Frame *newNode = new Frame;
        copyImageData(imageData[i], newNode->image);
        if (i == 0) {
            result = newNode;
        } else {
            last->next_frame = newNode;
        }
        last = newNode;
    }
	return result;
}

// TODO 2
// 
// Set the num_vehicles field in each frame to be the number of vehicles in its image.
// 
// head:	Pointer to the head of linked list
// 
void setNumOfVehicles(Frame *head)
{
    for (Frame *p = head; p; p = p->next_frame) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (p->image[i][j] == '*') {
                    count += 1;
                }
            }
        }
        p->num_vehicles = count;
    }
}

// TODO 3
// 
// Remove the frames that contain no vehicles.
// 
// head:	Pointer to the head of linked list
// 
void removeFramesWithNoVehicles(Frame *&head)
{

}

// Given function
// 
// Prints out the frame linked list, specified by head.
// 
// head:	Pointer to the head of linked list to be printed
// 
void printFrameLinkedList(const Frame *head)
{
	for (const Frame *curr = head; curr != nullptr; curr = curr->next_frame) {
		cout << "Number of vehicles: " << curr->num_vehicles << endl;

		for (int r = 0; r < ROWS; ++r) {
			for (int c = 0; c < COLS; ++c) {
				cout << curr->image[r][c];
			}
			cout << endl;
		}
	}

	cout << endl;
}
