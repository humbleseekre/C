//
//  singleLinkListn.hpp
//  linkedlist
//
//  Created by Nilendra Nimbalkar on 4/4/20.
//  Copyright © 2020 Nilendra Nimbalkar. All rights reserved.
//

#ifndef singleLinkListn_hpp
#define singleLinkListn_hpp

#include <stdio.h>

/*
 link list structure
 */
typedef struct linklist
{
    int val;
    linklist *next;
} ll;

void insertAtPos(int value, ll **head, int pos);
void reverseLinkList(ll **head);
void deleteNodeAtNPos(int pos, ll **head);
void insertNode(int temp, ll **head);
void printNodes(ll *head);

#endif /* singleLinkListn_hpp */
