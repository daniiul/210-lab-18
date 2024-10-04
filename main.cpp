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


int main()
{
    Node *head = nullptr;

    int entry;
    bool addReview = true;

    cout << "Which linked list method should we use?" << endl;
    cout << setw(61) << "[1] New nodes are added at the head of the linked list" << endl;
    cout << setw(61) << "[2] New nodes are added at the tail of the linked list" << endl;
    cout << "       Choice: ";
    cin >> entry;

    while(addReview)
    {

    }
}

Node* addNodeHead(Node *head, double rating, string comment)
{
    Node *newRating = new Node;
    if (!head)
    {
        head = newRating;
        newRating->next = nullptr;
        newRating->rating = rating;
        newRating->comment = comment;
    }
    else
    {
        newRating->next = head;
        newRating->rating = rating;
        newRating->comment = comment;
        head = newRating;
    }
    return head;
}

Node* addNodeTail(Node *head, double rating, string comment)
{
    Node *newRating = new Node;
    Node *temp = new Node;
    temp = head
    if (!head)
    {
        head = newRating;
        newRating->next = nullptr;
        newRating->rating = rating;
        newRating->comment = comment;
    }
    else
    {
        while (temp->next != nullptr)
            temp = temp->next;
        newRating->next = nullptr;
        newRating->rating = rating;
        newRating->comment = comment;
        temp->next = newRating;
    }
    return head;
}


