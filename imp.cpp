//Matthew Adler
//Professor Fant
//Prog 2
//This file is the implementation file of all functions for the following classes: Manage, Node--These classes are the data structures. Manage has a pointer to an array of doubly linked lists.
//Manage has an array of head ptrs;
//Node has a Base(abstract base class) pointer;
//The following classes are the hierarchy, Base, home, obstacle, player.These classes represent obstacles in a game of laser tag. 
#include "class.h"
Manage::Manage(){
    head= new Node*[2];
    for (int i=0; i<2; ++i){
        head[i]=NULL;
    }
}
Manage::~Manage(){

    wrappLoopRemoveAll();
    /*
       if (head){//if array
       for (int i=0; i<2; ++i){
       if (head[i]){
       removeAll(head[i]);
       }
       }
       }
       delete head;//delete whole array
       */
}
int Manage::wrappLoopRemoveAll(){
    if (!head)
        return 0;
    int i=0;
    wrappRemoveAll(i);
}
int Manage::wrappRemoveAll(int i){
    if (i==2){
        if (head){
            delete [] head;
            head=NULL;
        }
        return 1;
    }
    if (head[i]){
        removeAll(head[i]);
    }
    wrappRemoveAll(i+1);
}

int Manage::loopRetrieve(char toGet){
    if (!head)
        return 0;
    int i=0;
    wrappRetrieve(toGet,i);
}
int Manage::wrappRetrieve(char toGet, int &i){
    if (i==2)
        return 0;

    retrieve(toGet,head[i+1]);
}

int Manage::retrieve(char toGet, Node *head){
    if (!head)
        return 0;
    if (toGet==head->getData()){
        head->display();
    }
    retrieve(toGet,head->getNext());
}

int Manage::removeAll(Node *&head){
    if (!head)
        return 1;
    removeAll(head->getNext());
    delete head;
    head=NULL;
}
Manage::Manage(Manage &src){
    int i=0;
    copyWrapp(src, i);
}
int Manage:: copyWrapp(Manage &src,int i){
    if (i=2)
        return 1;
    copy(src.head[i], head[i]);
    copyWrapp(src, i+1);
}
int Manage:: copy(Node *src, Node *dest){
    if (!src)
        return 1;
    dest= new Node;
    dest->setPtr(src->getPtr());
    copy(src->getNext(), dest->getNext());
    if (dest->getNext()){
        dest->getNext()->setPrev(dest);
    }
}
int Manage::forLoop(char data){//to remove specific obstacle
    if (!head)
        return 0;
    int i=0;
    removeWrapper(data, i); 
}
int Manage::removeWrapper(char data, int i){
    if (!head){//if no array;
        return 0;
    }
    if (i==2){
        return 1;
    }
    remove(head[i], data);
    removeWrapper(data, i+1);//like our for loop 
}

int Manage::remove(Node *&head, char data){
    if (!head)
        return 0;
    remove(head->getNext(), data);
    if (head->getData()==data){
        Node *temp = head;
        head=head->getNext();//move head;
        if (head){
            head->setPrev(temp->getPrev());
        }
        temp->setNext(NULL);
        temp->setPrev(NULL);
        delete temp;
        temp=NULL;
    }
}

int Manage::insert(int index, int data){
    if (!head[index]){
        head[index]=new Node;
        head[index]->insert(data);
    }
    else{
        Node *temp= new Node;
        temp->insert(data);
        temp->setNext(head[index]);
        head[index]->setPrev(temp);
        // temp->getNext()->setPrev(temp);//CHECK
        head[index]=temp;
    }
    return 1;
}

int Manage::display(){
    if (head){
        for (int i=0; i<2; ++i){
            if (head[i]){
                cout<<"\n index "<<i<<endl;
                display(head[i]);
            }
        }
    }
    return 1;
}
int Manage::display(Node *head){
    if(!head)
        return 0;
    head->display();
    display(head->getNext());
}
Node::Node(){
    //data=0;
    ptr=NULL;
    next=NULL;
    prev=NULL;
}

Node::~Node(){
    if (ptr){
        delete ptr;
        ptr=NULL;
    }
}

Base *Node::getPtr(){
    if (ptr){
        return ptr;
    }
}
int Node:: setPtr(Base *toSet){
    if (toSet){
        ptr=toSet;
        return 1;
    }
    return 0;
}

Node::Node(Node &src){
    copy(src);
}

int Node::copy(Node &src){
    Obstacle *oPtr= dynamic_cast<Obstacle*>(src.ptr);
    Home *hPtr= dynamic_cast<Home*>(src.ptr);
    Player *pPtr= dynamic_cast<Player*>(src.ptr); 

    if (oPtr){//obstacle
        ptr= new Obstacle(*oPtr);
    }
    else if (hPtr){//home
        ptr= new Home (*hPtr);
    }
    else if (pPtr){//player
        ptr= new Player (*pPtr);
    }
    else
        ptr=NULL;
    return 1;
}

int Node::insert(int toInsert){
    if (toInsert<=4){
        ptr= new Obstacle;
    }
    if (toInsert<=8 && toInsert>4){
        ptr= new Home;
    }
    if (toInsert>8){
        ptr= new Player;
    }
    return 1;
}

char Node:: getData(){//gets name of obstacle
    if(ptr){
        return ptr->getData();
    }
    return 'z';
}

int Node::display(){
    if (ptr){
        cout<<"Name of obstacle: ";
        cout<<ptr->getData()<<endl;
    }
    return 1;

}
Node *& Node::getNext(){
    return next;
}

int Node::setNext(Node *toSet){
    next=toSet;
    return 1;
}

Node *& Node::getPrev(){
    return prev;
}

int Node::setPrev(Node * toSet){
    prev=toSet;
    return 1;
}/*
    int Node::getData(){
    return data;
    }
    */

Base::Base(){}
Base::~Base(){}
Base::Base(Base&src){
    type=src.type;
    ammo=src.ammo;
    location= src.location;
    health=src.health;
}
int Base::setHealth(int data){}
int Base::addAmmo(){}
int Base::StartOver(){}
char Base::getData(){}

Obstacle::Obstacle():Base(){
    type='o';
    ammo=100;
    location =0;
    health=100;
}
Obstacle::~Obstacle(){};
Obstacle::Obstacle(Obstacle &src):Base(src){
    type=src.type;
    ammo=src.ammo;
    location=src.location;
    health=src.health;
}
int Obstacle::setHealth(int data){
    health+-10;
    return 1;
}
int Obstacle::addAmmo(){
    ammo-=10;
    return 1;
}
int Obstacle::StartOver(){
    location=0;
    return location;
}
char Obstacle::getData(){
    cout<<"type "<<type<<endl;
    cout<<"ammo "<<ammo<<endl;
    cout<<"location "<<location<<endl;
    return type;
}

Home::Home():Base(){
    type='h';
    ammo=100;
    location =0;
    health=100;
}
Home::~Home(){
}
Home::Home(Home &src):Base(src){
    type=src.type;
    ammo=src.ammo;
    location=src.location;
    health=src.health;
}
int Home::setHealth(int data){
    health+=data;
    return 1;
}
int Home::addAmmo(){
    int x=100;
    x+=ammo;
    return ammo;
}
int Home::StartOver(){
    location =0;
    return 0;
}
char Home::getData(){
    cout<<"type "<<type<<endl;
    cout<<"ammo "<<ammo<<endl;
    cout<<"location "<<location<<endl;
    return type;
}
Player::Player():Base(){
    health=40;
    type='p';
    ammo=50;
    location =1;
}
Player::~Player(){
}
Player::Player(Player &src):Base(src){
    type=src.type;
    ammo=src.ammo;
    location=src.location;
    health=src.health;
}

int Player::setHealth(int data){
    health+=data;
    return 1;
}
int Player::addAmmo(){
    int x=50;
    x+=ammo;
    return ammo;
}
int Player::StartOver(){
    location =0;
    return 0;
}
char Player::getData(){
    cout<<"type "<<type<<endl;
    cout<<"ammo "<<ammo<<endl;
    cout<<"location "<<location<<endl;
    return type;
}




