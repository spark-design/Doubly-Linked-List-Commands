/*
Student Name: Connor Sparkman
Student NetID: cps260
Compiler Used: Visual Studio
*/
#pragma once
#include <iostream>
#include <sstream>
#include <string>

using std::istream;
using std::stringstream;
using std::string;
using std::endl;

class Node
{
public:
    string stringData;
    int data;
    Node* next;
    Node* prev;

    Node() :
        stringData(""), data(0), next(nullptr), prev(nullptr) {}

    Node(string stringData, int data) :
        stringData(stringData), data(data), next(nullptr), prev(nullptr) {}

    Node(string stringData, int data, Node* next, Node* prev) :
        stringData(stringData), data(data), next(next), prev(prev) {}
};