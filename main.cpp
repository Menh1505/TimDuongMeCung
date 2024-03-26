#include <iostream>
#include "Queue.h"
#include <fstream>
using namespace std;

bool TimDuong(int **MeCung, int size)
{
    int x, y;
    cout << "\nNhap toa do bat dau (x,y): ";
    cin >> x >> y;

    Queue *que = new Queue();
    que->push(new Node(x, y));

    cout << "\nNhap toa do ket thuc (x,y): ";
    cin >> x >> y;

    while(!que->empty())
    {
        if(que->front()->x == x && que->front()->y == y)
            return true;

        Node* tmp = que->front();
        if((tmp->x != size - 1) && MeCung[tmp->x + 1][tmp->y] == 1)
            que->push(new Node(tmp->x + 1, tmp->y));

        if((tmp->x != 0) && MeCung[tmp->x - 1][tmp->y] == 1)
            que->push(new Node(tmp->x - 1, tmp->y));

        if((tmp->y != size - 1) && MeCung[tmp->x][tmp->y + 1] == 1)
            que->push(new Node(tmp->x, tmp->y + 1));

        if((tmp->y != 0) && MeCung[tmp->x][tmp->y - 1] == 1)
            que->push(new Node(tmp->x, tmp->y - 1));
        
        MeCung[tmp->x][tmp->y] = 0;
        que->pop();
    }
    return false;
}


int main()
{
    int sizeMeCung;
    
    fstream f("MeCung.txt"); // Nhap me cung vao tu file

    f >> sizeMeCung; // lay kich thuoc me cung
    int **MeCung = new int*[sizeMeCung]; //khoi tao con tro cap 2 va cap phat 

    for(int i = 0; i < sizeMeCung; ++i)
    {
        MeCung[i] = new int[sizeMeCung]; // cap phat con tro cap 1
    }
    
    for(int i = 0; i < sizeMeCung; ++i)
    {
        for(int j = 0; j < sizeMeCung; ++j)
        {
            f >> MeCung[i][j]; // nhap me cung
        }
    }

    if(TimDuong(MeCung, sizeMeCung)) // tim duong
    {
        cout << "\nTim thay duong di";
    }
    else
    {
        cout << "\nKhong tim thay duong di";
    }

    for(int i = 0; i < sizeMeCung; ++i) // giai phong
    {
        delete[] MeCung[i];
    }
    delete[] MeCung; 
    return 0;
}