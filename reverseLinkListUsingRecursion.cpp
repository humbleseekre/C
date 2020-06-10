//
//  reverseLinkListUsingRecursion.cpp
//  linkedlist
//
//  Created by Nilendra Nimbalkar on 4/4/20.
//  Copyright © 2020 Nilendra Nimbalkar. All rights reserved.
//

#include "reverseLinkListUsingRecursion.hpp"
#include <iostream>

using namespace std;

void reverseLinkListRecursionPrint(ll *head)
{
    if(head == NULL)
    {
        return;
    }/Users/neil/Programming/linkedlist/linkedlist/main.cpp
    if(head->next != NULL)
    {
        reverseLinkListRecursionPrint(head->next);
    }
    cout << head->val;
}

void forwardLinkListRecursionPrint(ll *head)
{
    if(head == NULL)
    {
        return;
    }
    cout << head->val << " ";
    
    if(head->next != NULL)
    {
        forwardLinkListRecursionPrint(head->next);
    }
}

void reverseLinkListRecursion(ll *curr, ll **head)
{
    if(curr->next == NULL)
    {
        *head = curr;
        return;
    }
    reverseLinkListRecursion(curr->next, head);
    ll *reverseNext = curr->next;
    reverseNext->next = curr;
    curr->next = NULL;
}
