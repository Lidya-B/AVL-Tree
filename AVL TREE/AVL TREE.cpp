//*****************************************************************************************************
//
//		File:					AVLTREE.CPP
//
//		This program will impliment and test a AVL tree class.
//	
//		Other files required: 
//         1. AVL.h
//         2. Stock.h 
//			
//*****************************************************************************************************

#include "AVL.h" 
#include "Stock.h"   
#include <iostream>
#include <fstream>
#include <cstdlib> 

//*****************************************************************************************************

using namespace std;

//*****************************************************************************************************

int main()
{
    AVLTree<int> intTree;

    for (int i = 0; i < 10; ++i) 
    {
        int randomValue = rand() % 5000 + 1; 
        intTree.insert(randomValue);
    }

    cout << "Inorder traversal: ";
    intTree.inorder();
    cout << endl;

    cout << "Preorder traversal: ";
    intTree.preorder();
    cout << endl;

    cout << "Postorder traversal: ";
    intTree.postorder();
    cout << endl;

    cout << "Height of the tree: " << intTree.height() << endl;

    intTree.destroy();
    ifstream inputFile("Stock.txt");
    if (!inputFile.is_open()) 
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    AVLTree<Stock> stockTree;

    string companyName, stockSymbol, priceStr;

    while (getline(inputFile, companyName) &&
        getline(inputFile, stockSymbol) &&
        getline(inputFile, priceStr))
    {
        try
        {
            double price = stod(priceStr);
            Stock newStock(companyName, stockSymbol, price);
            stockTree.insert(newStock);
        }
        catch (const invalid_argument& e)
        {
            cout << "Invalid price format: " << priceStr << endl;
        }
    }

    inputFile.close(); 

    char choice;
    do {
        cout << "Choose an option:" << endl;
        cout << "a) Display a stock's name given its symbol" << endl;
        cout << "b) Display a stock's price given its symbol" << endl;
        cout << "c) Insert a new stock" << endl;
        cout << "d) Display all stocks" << endl;
        cout << "e) Quit" << endl;
        cin >> choice;

        switch (choice) 
        {
            case 'a':
            {
                string symbol;
                cout << "Enter stock symbol: ";
                cin >> symbol;
                cin.ignore();
                Stock* foundStock = stockTree.search(Stock("", symbol, 0));
                if (foundStock != nullptr)
                {
                    cout << "Stock name: " << foundStock->getName() << endl;
                }
                else
                {
                    cout << "Stock not found." << endl;
                }
                break;
            }
            case 'b':
            {
                string symbol;
                cout << "Enter stock symbol: ";
                cin >> symbol;
                cin.ignore(); 
                Stock* foundStock = stockTree.search(Stock("", symbol, 0));
                if (foundStock != nullptr)
                {
                    cout << "Stock price: " << foundStock->getPrice() << endl;
                }
                else
                {
                    cout << "Stock not found." << endl;
                }
                break;
            }
            case 'c':
            {
                string name, symbol;
                double price;
                cin.ignore();
                cout << "Enter stock name: ";
                getline(cin, name);
                cout << "Enter stock symbol: ";
                cin >> symbol;
                cout << "Enter stock price: ";
                cin >> price;
                Stock newStock(name, symbol, price);
                stockTree.insert(newStock);
                cout << "Stock inserted successfully." << endl;
                break;
            }
            case 'd':
            {
                cout << "All stocks:" << endl;
                stockTree.inorder();
                break;
            }
            case 'e':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'e');

    return 0;
}
//*****************************************************************************************************
