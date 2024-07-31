//*****************************************************************************************************
//
//		File:					Node.h
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