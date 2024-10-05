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

    // gets the method for creating linked list
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

        if (c == 'n' || c == 'N')
            review = false;
        else if(c == 'y' || c == 'Y')
            continue;
    }
    cout << "Outputting All Reviews: " << endl;

    output(head);

}

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

void output(Node* head)
{
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

