#ifndef Node_H
#define Node_H


class Node
{
    public:
        int x;
        int y;
        Node *next;

        Node()
        {
            x = 0;
            y = 0;
            next = nullptr;
        }
        Node(int _x, int _y)
        {
            x = _x;
            y = _y;
            next = nullptr;
        }
        ~Node()
        {
            
        }
};

#endif // Element_H