#include"LinkList.h"
#include<iostream>

using namespace std;

int main(){
    LinkList<int> Link(2);
    Link.print();
    cout << Link.getlength() << endl;
    // cout << Link.getelem(3) << endl;;
    // cout << Link.getindex(5);
    Link.insert(10, 1);
    Link.print();
    Link.insert(10, 5);
    Link.print();
    Link.del(6);
    Link.print();
    Link.del(1);
    Link.print();
}