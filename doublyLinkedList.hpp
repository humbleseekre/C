//
//  doublyLinkedList.hpp
//  doublyLinkList
//
//  Created by Nilendra Nimbalkar on 4/4/20.
//  Copyright © 2020 Nilendra Nimbalkar. All rights reserved.
//

#ifndef doublyLinkedList_hpp
#define doublyLinkedList_hpp

#include <stdio.h>

typedef struct doublyLinkedList
{
    int val;
    doublyLinkedList *next;
    doublyLinkedList *prev;
}dll;

void insertAtHead(int value, dll **head);
void printDoublyLinkedListForward(dll *head);
void reversePrint(dll *head);
void insertAtTail(int value, dll **head);

#endif /* doublyLinkedList_hpp */
