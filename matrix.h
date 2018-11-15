#ifndef MATRIX_H
#define MATRIX_H

#include "node.h"

using namespace std;

template <typename T>
class Matrix {
    private:
        Node<T>* cornerNode;
        int columns;
        int rows;

    public:
        Matrix();
        Matrix(int sizeX, int sizeY)
        {
            this -> columns = sizeX;
            this -> rows = sizeY;

            Node<T> * lastRow = new Node<T>(rows + 1, 0, 0, nullptr, nullptr);
            Node<T> * lastColumns = new Node<T>(0, columns + 1, 0, nullptr, nullptr);

            this -> cornerNode = new Node<T>(0,0,0, lastRow, lastColumns);
            cout << "Matrix Succesfully Set up. Rows = " << rows << " Columns = " << columns << " \(^ヮ^)/." << endl;
        };

        Node<T> * find(int row, int column)
        {
            Node * currentNode = cornerNode;
            Node * foundNode = nullptr;

            while ((currentNode -> x) < row)
            {
                currentNode = currentNode -> down;
            }

            if (currentNode -> x == row)
            {
                while ((currentNode -> y) < column)
                {
                    currentNode = currentNode -> next;
                }
                if (currentNode -> y == column)
                    foundNode = currentNode;
            }

            return foundNode;   
        }

        void set(int x, int y, T data)
        {
            Node<T> * aboveNode = new Node<T>();
            Node<T> * previousNode = nullptr;
            Node<T> * currentNode = new Node<T>();

            currentNode = find(x, y);

            if (currentNode)
            {
                currentNode -> value = data;
                if (currentNode -> value == 0) 
                {
                    findPrevUp(row, col) -> down = currentNode -> down;
                    findPrevLeft(row, col) -> right = currentNode -> right;
                }
            }

        };

        Node<T> * findPrevUp(int row, int column)
        {
            Node<T> * currentNode = cornerNode;
            Node<T> * previousNode = nullptr;

            while (currentNode -> x < column)
                currentNode = currentNode -> next;

            while (currentNode -> y < row)
            {
                previousNode = currentNode;
                currentNode = currentNode -> down;
            }

            return previousNode;
        }

        Node<T> * findPrevLeft(int row, int column)
        {
            Node<T> * currentNode = cornerNode;
            Node<T> * previousNode = nullptr;

            while (currentNode -> y < row)
                currentNode = currentNode -> down;

            while (currentNode -> x < column)
            {
                previousNode = currentNode;
                currentNode = currentNode -> next;
            }

            return previousNode;
        }

        T operator()(int x, int y)
        {
            return find(x,y) -> data;
        }

        Matrix<T> operator*(Matrix<T> other);
        Matrix<T> operator*(T scalar);
        Matrix<T> operator+(Matrix<T> other);
        Matrix<T> operator-(Matrix<T> other);
        Matrix<T> transposed();
        Matrix<T> operator=(Matrix<T> other);

        //~Matrix();
};

#endif