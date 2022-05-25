//Matthew Adler
//Professor Fant
//Prog 2
//11/8/2019
//This program simulates a game of laser tag. The program is just the course for a game of laser tag, i.e. and array of doubly linked lists.
//The purpose of this file is to manage the classes:
//Abstract base class: base
//Derived: Obstactle, Home, and Player
//Manager/player class which manages Node class, array of Node**head
//Node class which has a base class pointer, Node *next, Node *prev
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

class Manage{//implement copy constructor please make copy of array of DLL
    public:
        Manage();
        ~Manage();

        int wrappLoopRemoveAll();
        int wrappRemoveAll(int i);
        Manage(Manage & src);
        int loopRetrieve(char toGet);
        int wrappRetrieve(char toGet, int &i);
        int retrieve(char toGet, class Node *head);
        int copyWrapp(Manage &src,int i);//forloop
        int copy(Manage &src);//copies DLL
        int copy(class Node *src, class Node *dest);
        int insert(int data);//based off of number, create ptr,create ptr and 
        //pass into Node's insert function.
        int removeAll();
        int insert(int index, int data);
        int remove(char data);
        int display();
        int retrieve();
        int setHealth(int toSet);
        int getHealth();
        //        int removeAll(int index);
        int removeWrapper(char data, int i);
        int forLoop(char data);
    private:
        int remove(class Node *&head, char data);
        int display(class Node *head);
        int removeAll(class Node *&head);
        int size;
        class Node**head;
};

class Node{
    public:
        Node();
        ~Node();
        Node(Node &src);//copy constructor
        int copy(Node & src);//RTTI
        int insert(int data);//insertBase*ptr, data as test
        char getData();
        int remove();
        int  display();
        Node *&getNext();
        int setNext(Node *toSet);
        Node *& getPrev();
        int setPrev(Node *toSet);
        class Base * getPtr();
        int setPtr(class Base *toSet);
    private:
        class Base*ptr;//ptr to base class;
        Node *next;
        Node *prev;
};

class Base{
    public:
        Base();
        virtual ~Base();
        Base(Base &src);
        virtual int setHealth(int data)=0;
        virtual int addAmmo()=0;
        virtual int StartOver()=0;
        virtual char getData()=0;
    protected:
        char type;
        int ammo;
        int location;
        int health;
};
class Obstacle: public Base{
    public:
        Obstacle();
        ~Obstacle();
        Obstacle(Obstacle &src);
        int setHealth(int data);
        int addAmmo();
        int StartOver();
        char getData(); 
        int setHealth();
};
class Home:public Base{
    public:
        Home();
        ~Home();
        Home(Home &src);
        int setHealth(int data);
        int addAmmo();
        int StartOver();
        char getData(); 
        int setHealth();
};
class Player:public Base{
    public:
        Player();
        ~Player();
        Player(Player &obj);
        int setHealth(int data);
        int addAmmo();
        int StartOver();
        char getData(); 
        int setHealth();

};
