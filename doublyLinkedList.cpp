//
//  doublyLinkedList.cpp
//  doublyLinkList
//
//  Created by Nilendra Nimbalkar on 4/4/20.
//  Copyright © 2020 Nilendra Nimbalkar. All rights reserved.
//

#include "doublyLinkedList.hpp"
#include <iostream>

using namespace std;

dll* createNewNode(int value)
{
    dll *tempNode = new (dll);
    tempNode->next = NULL;
    tempNode->prev = NULL;
    tempNode->val = value;
    return tempNode;
}

void insertAtHead(int value, dll **head)
{
    dll *newNode = createNewNode(value);
    
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    (*head)->prev = newNode;
    newNode->next = *head;
    *head = newNode;
}

void printDoublyLinkedListForward(dll *head)
{
    if(head == NULL)
    {
        return;
    }
    
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return;
}

void reversePrint(dll *head)
{
    cout << "Printing link list in reverse order \n";
    //cout << head->val << endl;
    
    if(head == NULL)
    {
        return;
    }
    
    while(head->next != NULL)
    {
        head = head->next;
    }
    
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->prev;
    }
    cout << endl;
}

void insertAtTail(int value, dll **head)
{
    dll *insertNode = createNewNode(value);
    dll *temp = *head;
    if (temp == NULL)
    {
        *head = insertNode;
        return;
    }
    
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = insertNode;
    insertNode->prev = temp;
}

