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

const std::string NAMES[] = {
        "Alice",   "Bob",     "Carol",   "Dave",    "Eve",
    "Frank",   "Grace",   "Hank",    "Ivy",     "Jake",
    "Kara",    "Leo",     "Mia",     "Nate",    "Olivia",
    "Pedro",   "Quinn",   "Rachel",  "Sam",     "Tina",
    "Uma",     "Victor",  "Wendy",   "Xander",  "Yara",
    "Zoe",     "Aaron",   "Bella",   "Carlos",  "Diana"
    };

    const int NAME_COUNT = 30;

    const std::string DRINKS[] = {
        "Latte",          "Espresso",       "Cappuccino",
    "Cold Brew",      "Mocha",          "Americano",
    "Flat White",     "Macchiato",      "Cortado",
    "Oat Milk Latte", "Vanilla Latte",  "Caramel Macchiato",
    "Irish Coffee",   "Chai Latte",     "Matcha Latte"
    };

    const int DRINK_COUNT = 15;

struct Node {
    std::string customerName;
    std::string order;
    Node* next;

    Node(const std::string& name, const std::string& ord)
        : customerName(name), order(ord), next(NULL) {}
};

struct CoffeeQueue {
    Node* head;;
    Node* tail;
    int size;

    CoffeeQueue() : head(NULL), tail(NULL), size(0) {}

    bool isEmpty() const { return head == NULL; }

    void addCustomer(const std::string& name, const std::string& order) {
        Node* newNode = new Node(name, order);
        if(tail != NULL) tail->next = newNode;
        else head = newNode;
        tail = newNode;
        ++size;
    }

    bool dequeue(std::string& nameOut, std::string& orderOut) {
        if(isEmpty()) return false;
        nameOut = head->customerName;
        orderOut = head->order;
        Node* old = head;
        head = head->next;
        if(head == NULL) tail = NULL;
        delete old;
        --size;
        return true;
    }

    ~CoffeeQueue() {
        while(head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main() {

    return 0;
}