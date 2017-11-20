#include "lab10.h"
#include "frame.h"

using namespace std;

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