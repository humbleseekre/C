//
//  main.cpp
//  linkedlist
//
//  Created by Nilendra Nimbalkar on 3/30/20.
//  Copyright © 2020 Nilendra Nimbalkar. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 link list structure
 */
typedef struct linklist
{
    int val;
    linklist *next;
} ll;

/*
 Global head to track linked list head
 */
ll *head = NULL;

void insertAtPos(int value, ll **head, int pos)
{
    int temp = 1;
    ll *currPtr = *head;
    if(*head == NULL)
    {
        return;
    }
    
    ll *newNode = new(ll);
    
    if(pos == 1)
    {
        newNode->val = value;
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    while(currPtr != NULL)
    {
        if(temp++ == pos-1)
        {
            newNode->val = value;
            newNode->next = currPtr->next;
            currPtr->next = newNode;
            return;
        }
        currPtr = currPtr->next;
    }
    cout << "Invalid position: Pos is out of range" << endl;
}

void reverseLinkList(ll **head)
{
    ll *prev = NULL, *next = NULL, *curr = NULL;
    curr = *head;
    
    if(curr == NULL)
    {
        return;
    }
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    *head = prev;
}

void deleteNodeAtNPos(int pos, ll **head)
{
    int temp = 1;
    ll *tempPtr = *head;
    
    if(temp == pos)
    {
        *head = (*head)->next;
        free(tempPtr);
        return;
    }
    
    while(tempPtr != NULL)
    {
        if(temp++ == pos-1)
        {
            ll *delNode = tempPtr->next;
            tempPtr->next = tempPtr->next->next;
            free(delNode);
            return;
        }
        tempPtr = tempPtr->next;
    }
}

void insertNode(int temp, ll **head)
{
    ll *newNode = new(ll);
    newNode->val = temp;
    newNode->next = *head;
    *head = newNode;
}

void printNodes(ll *head)
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
}

int main(int argc, const char * argv[])
{
    while(true)
    {
        int temp, x=0, y=0;
        // insert code here...
        for(int x = 0; x <4; x++)
        {
            cout << "Enter a new node ";
            cin >> temp;
            insertNode(temp, &head);
            printNodes(head);
        }
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
        printNodes(head);
    }
    
    return 0;
}
