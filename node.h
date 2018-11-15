#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node {
    int x, y;
    T data;
    Node* next;
    Node* down;

    public:
        Node();
        Node(int xCoordinate, int yCoordinate, T value, Node<T> * rightNode, Node<T> * downNode)
        {
            this -> x = xCoordinate;
            this -> y = yCoordinate;
            this -> data = value;
            this -> next = rightNode;
            this -> down = downNode;
            cout << "Node Created (☆ω☆)" << endl;
        }
};

#endif