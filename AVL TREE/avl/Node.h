//*****************************************************************************************************
//
//		File:					Node.h
//
//		Student:				Lidya Belew
//
//		Assignment:				assigment 8
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					04/01/2024
//
//
//		This program will impliment and test a AVL tree class.
//	
//		Other files required: 
//         1. none 
//			
//*****************************************************************************************************
template <typename T>
struct Node
{
    T value;
    int bFactor;
    Node* left;
    Node* right;
};

//*****************************************************************************************************
