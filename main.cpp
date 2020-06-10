//
//  main.cpp
//  linkedlist
//
//  Created by Nilendra Nimbalkar on 3/30/20.
//  Copyright © 2020 Nilendra Nimbalkar. All rights reserved.
//

#include <iostream>
#include "singleLinkList.hpp"
#include "reverseLinkListUsingRecursion.hpp"

using namespace std;

/*
 Global head to track linked list head
 */
ll *head = NULL;

int main(int argc, const char * argv[])
{
    int temp, x=0, y=0;
    // insert code here...
    while(true)
    {
        for(int x = 0; x <4; x++)
        {
            cout << "Enter a new node ";
            cin >> temp;
            insertNode(temp, &head);
            printNodes(head);
        }
        /*
        cout << "enter value and position ";
        cin >> x >> y;
        insertAtPos(x, &head, y);
        printNodes(head);
        cout << "Enter the position number to delete the node on ";
        cin >> x;
        deleteNodeAtNPos(x, &head);
        printNodes(head);
        
        cout << "Reversing the link list " << endl;
        reverseLinkList(&head);
        printNodes(head);*/
        cout << "Now printing using recursion......." << endl;
        reverseLinkListRecursionPrint(head);
        
        cout << "Now printing forward list using recursion" << endl;
        forwardLinkListRecursionPrint(head);
        
        //Reverse the link list using recurssion
        reverseLinkListRecursion(head, &head);
        
        cout << "Now printing forward list using recursion" << endl;
        forwardLinkListRecursionPrint(head);
    }
    
    return 0;
}
