//
//  main.cpp
//  doublyLinkList
//
//  Created by Nilendra Nimbalkar on 4/4/20.
//  Copyright © 2020 Nilendra Nimbalkar. All rights reserved.
//

#include <iostream>
#include "doublyLinkedList.hpp"

dll *head = NULL;

int main(int argc, const char * argv[])
{
    // insert code here...
    insertAtHead(1, &head);
    insertAtHead(2, &head);
    printDoublyLinkedListForward(head);
    reversePrint(head);
    insertAtTail(3, &head);
    printDoublyLinkedListForward(head);
    reversePrint(head);
    return 0;
}
