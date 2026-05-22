/*
    Vendor Booths = 4.
    1. Coffee -> singly linked list struct/Node
    2. Muffins -> std::deque
    3. Bracelets -> std::vector
    4. Smoothies -> std::list

    Simulation rules:
     - Run 10 times/rounds
     - Queue starts with 3 customres
     - Each round: Front customer is always served (if any in line), and 50% chance someone joins
     - I need to use rand() i believe, for the customer's data

*/

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

struct Node {
    std::string customerName;
    std::string order;
    Node* next;
};

struct CoffeeQueue {
    Node* head;
    Node* tail;
    int size;
};