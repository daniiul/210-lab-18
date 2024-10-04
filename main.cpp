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

int main()
{
    Node *head = nullptr;

    int entry;
    bool review = true;

    cout << "Which linked list method should we use?" << endl;
    cout << setw(61) << "[1] New nodes are added at the head of the linked list" << endl;
    cout << setw(61) << "[2] New nodes are added at the tail of the linked list" << endl;
    cout << "       Choice: ";
    cin >> entry;

    while(review)
    {
        char c;
        head = addReview(head, entry);
        cout << "Enter another review? Y/N: ";
        cin >> c;

        if (c == "y" || c == "Y")
            review = false;
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

Node* addReview(Node *head, int entry)
{
    int rating;
    string comment;

    cout << "Enter review rating 0-5: ";
    cin >> rating;

    cout << "Enter review comments: ";
    getline(cin, comment);

    if (entry == 1)
        head = addNodeHead(head, rating, comment);
    else
        head = addNodeTail(head, rating, comment);

    return head;

}

