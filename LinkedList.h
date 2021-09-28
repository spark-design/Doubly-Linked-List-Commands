/*
Student Name: Connor Sparkman
Student NetID: cps260
Compiler Used: Visual Studio
*/
#pragma once
#include "Node.h"
#include <iostream>
#include <sstream>
#include <string>

using std::istream;
using std::stringstream;
using std::string;
using std::cout;
using std::endl;

class LinkedList
{
private:
    Node* head;
    Node* tail;

public:
    LinkedList() :
        head(nullptr), tail(nullptr) {}

    ~LinkedList();

    void append(string stringData, int data);
    void prepend(string stringData, int data);
    bool search(int data);
    bool remove(string stringData);

    void display();
    void displayReverse();
    void displayUntil(int data);
    bool find(string stringData);
    void length();
    bool insertBefore(string strArg1, int intArg1, string strArg3);
    bool insertAfter(string strArg1, int intArg1, string strArg3);
};