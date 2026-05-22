#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iomanip>

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

    const std::string MUFFINS[] {
        "Blueberry",       "Chocolate Chip",  "Banana Nut",
    "Lemon Poppy",     "Pumpkin",         "Cinnamon Sugar",
    "Double Chocolate","Cranberry Orange", "Carrot Walnut",
    "Strawberry",      "Peach Pecan",     "Maple Bacon",
    "Almond Cherry",   "Raspberry White Choc", "Coconut Lime"
    };

    const int MUFFIN_COUNT = 15;

    const std::string BRACELETS[] {
        "Rainbow Beaded",  "Woven Hemp",      "Silver Chain",
    "Custom Name Tag", "Knot Macrame",    "Gold Charm",
    "Star Pattern",    "Turquoise Beaded","Leather Wrap",
    "Pearl Strand",    "Morse Code",      "Braided Cotton",
    "Evil Eye Charm",  "Birthstone Band", "Infinity Knot"
    };

    const int BRACELET_COUNT = 15;

    const std::string COOKIES[] = {
        "Chocolate Chip",  "Snickerdoodle",   "Oatmeal Raisin",
    "Peanut Butter",   "Sugar",           "Double Fudge",
    "Shortbread",      "White Chocolate Macadamia", "Gingersnap",
    "Lemon Butter",    "Molasses",        "Almond Biscotti",
    "Salted Caramel",  "Red Velvet",      "Funfetti"
    };

    const int COOKIE_COUNT = 15;

    std::string randomName() { return NAMES[ rand() % NAME_COUNT]; }
    std::string randomDrink() { return DRINKS[ rand() % DRINK_COUNT]; }
    std::string randomMuffin() { return MUFFINS[ rand() & MUFFIN_COUNT]; }
    std::string randomBracelet() { return BRACELETS[ rand() % BRACELET_COUNT]; }
    std::string randomCookie() { return COOKIES[ rand() % COOKIE_COUNT]; }

    bool coinFlip() { return rand() % 2 == 0; }
    void printHeader(int round) { 
        std::cout << "\n";
        std::cout << "==========================================\n";
    }


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

typedef std::pair<std::string, std::string> Customer;
Customer makeCustomer(const std::string& name, const std::string& order) {
    return std::make_pair(name, order);
}

void runCoffeeRound(CoffeeQueue& q) {
    std:: cout << "  Coffee    | ";
    std::string name, order;
    if( q.dequeue(name, order))
    std:: cout << "Served: " << name << " (" << order << ")";
    else
        std:: cout << "Queue empty - no one served";
        
    if(coinFlip()) {
        std::string n = randomName(), o = randomDrink();
        q.addCustomer(n, o);
        std:: cout << " | Joined: " << n <<  " (" << o << ")";
    } else {
            std:: cout << " | No one joined";
    }
    std:: cout << "\n";

}

void runMuffinRound(std::deque<Customer>& q) {
    std::cout << "  Muffins   | ";

    if(!q.empty()) {
        std::cout << "Served: " << q.front().first
            << " (" << q.front().second << ")";
        q.pop_front();
    } else {
        std::cout << "Queue empty - no one served";
    }
    if(coinFlip()) {
        Customer c = makeCustomer(randomName(), randomMuffin());
        q.push_back(c);
        std::cout << "  | Joined: " << c.first << " (" << c.second << ")";
    }else {
        std::cout << "  | No one joined";
    }
    std::cout<<"\n";
}

void runBraceletRound(std::vector<Customer>& q) {
    std::cout << "  Bracelets | ";

    if(!q.empty()) {
        std::cout << "Served: " << q.front().first
        << " (" << q.front().second << ")";
        
    } else {
        std::cout << "Queue empty - no one served";
    }

    if(coinFlip()) {
        Customer c = makeCustomer(randomName(), randomBracelet());
        q.push_back(c);
        std::cout << "  | Joined: " << c.first << " (" << c.second << ")";
    } else {
        std::cout << "  | No one joined";
    }
    std::cout << "\n";
}

void runCookieRound(std::list<Customer>& q) {
    std:: cout << "  Cookies   | ";
    if(!q.empty()) {
        std::cout << "Served: " << q.front().first
        << " (" << q.front().second << ")";
        
    } else {
        std::cout << "Queue empty - no one served";
    }

    if(coinFlip()) {
        Customer c = makeCustomer(randomName(), randomBracelet());
        q.push_back(c);
        std::cout << "  | Joined: " << c.first << " (" << c.second << ")";
    } else {
        std::cout << "  | No one joined";
    }
    std::cout << "\n";
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    const int ROUNDS = 10;
    const int INIT_CUSTOMERS = 3;

    CoffeeQueue coffeeQ;
    std::deque<Customer> muffinQ;
    std::vector<Customer> braceletQ;
    std::list<Customer> cookieQ;

    std:: cout << "Initializing queues with "
            << INIT_CUSTOMERS << " customers each...\n";

    for(int i = 0; i < INIT_CUSTOMERS; ++i) {
        coffeeQ.addCustomer(randomName(), randomDrink());
        muffinQ.push_back(makeCustomer(randomName(), randomMuffin()));
        braceletQ.push_back(makeCustomer(randomName(), randomBracelet()));
        cookieQ.push_back(makeCustomer(randomName(), randomCookie()));
    }

    for(int round = 1; round <= ROUNDS; ++round) {
        printHeader(round);
        runCoffeeRound(coffeeQ);
        runMuffinRound(muffinQ);
        runBraceletRound(braceletQ);
        runCookieRound(cookieQ);
    }
    std::cout<<"\nSimulation complete\n";

    return 0;
}