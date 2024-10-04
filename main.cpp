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

    cout << "Which linked list method should we use?" << endl;
    cout << setw(10) << "[1] New nodes are added at the head of the linked list" << endl;
    cout << setw(5) << "[1] New nodes are added at the tail of the linked list" << endl;
}
