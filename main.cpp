// COMSC-210 | Lab 18 | Daniil Malakhov
// IDE used: Codeblocks
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node
{
    double rating;
    string comments;
    Node *next;
};

Node* addNodeHead(Node *, double, string);
Node* addNodeTail(Node *, double, string);
Node* addReview(Node*, int);
void output(Node*);

int main()
{
    Node *head = nullptr;

    int entry;
    bool review = true;

    // makes the user decide whether to end nodes to end or head of linked list
    cout << "Which linked list method should we use?" << endl;
    cout << setw(61) << "[1] New nodes are added at the head of the linked list" << endl;
    cout << setw(61) << "[2] New nodes are added at the tail of the linked list" << endl;
    cout << "       Choice: ";
    cin >> entry;

    //keeps asking for movie specifics such as rating and comments
    while(review)
    {
        char c;
        head = addReview(head, entry);
        cout << "Enter another review? Y/N: ";
        cin >> c;

        if (c == 'n' || c == 'N')
            review = false;
        else if(c == 'y' || c == 'Y')
            continue;
    }

    //outputs all elements of all nodes in linked list
    output(head);
}

// adds a node to the head of the linked list and populates it with given rating and comment
// arguments: Node object representing the head, double variable representing the rating of movie, string variable representing comments on movie
// returns: A node object representing the head
Node* addNodeHead(Node *head, double rating, string comment)
{
    Node *newRating = new Node;
    if (!head)
    {
        head = newRating;
        newRating->next = nullptr;
        newRating->rating = rating;
        newRating->comments = comment;
    }
    else
    {
        newRating->next = head;
        newRating->rating = rating;
        newRating->comments = comment;
        head = newRating;
    }
    return head;
}

// adds a node to the tail of the linked list and populates it with given rating and comment
// arguments: Node object representing the head, double variable representing the rating of movie, string variable representing comments on movie
// returns: A node object representing the head
Node* addNodeTail(Node *head, double rating, string comment)
{
    Node *newRating = new Node;
    Node *temp = new Node;
    temp = head;
    if (!head)
    {
        head = newRating;
        newRating->next = nullptr;
        newRating->rating = rating;
        newRating->comments = comment;
    }
    else
    {
        while (temp->next != nullptr)
            temp = temp->next;
        newRating->next = nullptr;
        newRating->rating = rating;
        newRating->comments = comment;
        temp->next = newRating;
    }
    return head;
}

// adds a review to the list by calling the specified add node method, gathers data from user to populate node
// arguments: a node object representing the head, an integer variable representing the method to use when adding nodes to linked list
// returns: A node object representing the head
Node* addReview(Node *head, int entry)
{
    double rating;
    string comment;

    cout << "Enter review rating 0-5: ";
    cin >> rating;

    cin.ignore();

    cout << "Enter review comments: ";
    getline(cin, comment);

    if (entry == 1)
        head = addNodeHead(head, rating, comment);
    else
        head = addNodeTail(head, rating, comment);

    return head;
}

// outputs all the reviews and comments per rating in the linked list and prints average of all reviews
// arguments: a node object representing the head
// returns: none
void output(Node* head)
{
    cout << "Outputting All Reviews: " << endl;

    if (!head) {
        cout << "No reviews in list" << endl;
        return;
    }

    int count = 1;
    double sum = 0;
    Node * current = head;

    while (current) {
        cout << "      > Review #" << count++ << ": " << current->rating << ": " << current->comments << endl;
        sum += current->rating;
        current = current->next;
    }

    cout << "      > Average: " << sum / (count - 1) << endl;
}

