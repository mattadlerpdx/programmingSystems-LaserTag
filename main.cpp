//Matt Adler
//Professor Fant
//Prog 2
//11/8/2019
//This file is the main interface, the place where the user can add, retrieve, display, and remove data, or in this case, obstacles from the laser tag obstacle course. 
#include "class.h"
int main(){

    Manage obj;
    srand(time(NULL));
    char homeData='h';//data to remove
    char playerData='p';
    char obstacleData='o';

    char homeRetrieve='h';
    char playerRetrieve='p';
    char obstacleRetrieve='o';//data of Obstacle type to retrieve
    int proceed=1;
    int response=0;
    int choice=0;
    for (int i=0; i<6; ++i){
        int index=rand()%2;
        int data= rand()%11;
        obj.insert(index, data);
    }

    while(proceed==1){
        cout<<"(1)Display course? (2)Display specific data for an Obstacle, (3) Delete a specifc obstacle? (4) RemoveAll"<<endl;
        cin>>response;
        cin.ignore(100, '\n');
        if (response==1){
            cout<<"Displaying data"<<endl;
            obj.display();
        }
        if (response==2){
            cout<<"Which obstacle do you want to display? (1) Home, (2)Player, (3) Obstacle "<<endl;
            cin>>choice;
            cin.ignore(100, '\n');
            if (choice==1){
                cout<<"Displaying data for all nodes that are type Home ";
                obj.loopRetrieve(homeRetrieve);
            }
            if (choice==2){
                cout<<"Displaying data for all nodes that are type Player ";
                obj.loopRetrieve(playerRetrieve);
            }
            if (choice==3){
                cout<<"Displaying data for all nodes that are type Obstacle ";
                obj.loopRetrieve(obstacleRetrieve);
            }
        }
        if (response==3){
            cout<<"Which obstacle do you want to delete? (1) Home, (2)Player, (3) Obstacle "<<endl;
            cin>>choice;
            cin.ignore(100, '\n');
            if (choice==1){
                obj.forLoop(homeData);
            }
            if (choice==2){
                obj.forLoop(playerData);
            }
            if (choice==3){
                obj.forLoop(obstacleData);
            }
            cout<<"After removal"<<endl;
            obj.display();
        }
        if (response==4){
            obj.wrappLoopRemoveAll();
        }
        cout<<"(1) Continue (2) Quit"<<endl;
        cin>>proceed;
        cin.ignore(100, '\n');
    }

}
