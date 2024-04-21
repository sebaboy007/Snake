
#include <string>
#include <iostream>
#include <thread>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <fstream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


int max_score;
int k=4,q=2,game_open=1,level,marime;
void task1()
{
    int c = 0;
    while(game_open)
    {
        c = 0;

        switch((c=getch()))
        {
        case KEY_UP:
            k=1;
            break;
        case KEY_DOWN:
            k=2;
            break;
        case KEY_LEFT:
            k=3;
            break;
        case KEY_RIGHT:
            k=4;
            break;

        }

    }
}
void task2()
{
    int a[100],b[100],l,pozi,pozj;
    a[1]=1;
    b[1]=1;
    pozi=rand()%marime+1;
    pozj=rand()%marime+1;
    while(game_open)
    {
        cout<<"SCOR: "<<q-2<<" MAX SCORE:"<<max_score<<endl;
        for(int i=1;i<=marime;i++)
        {
            for(int j=1;j<=marime;j++)
            {

                if(i==pozi && j==pozj)
                    if(a[1]==i && b[1]==j)
                    {
                        q++;
                        pozi=rand()%marime+1;
                        pozj=rand()%marime+1;
                    }
                    else
                        cout<<"o ";
                else
                {
                    for(l=1;l<=q;l++)
                    {
                        if(a[l]==i && b[l]==j)
                        {
                            cout<<"@ ";
                            break;
                        }

                    }
                    if(l>q)
                        cout<<"  ";
                }
            }
            cout<<"*";
            cout<<endl;
        }
        for(int i=1;i<=marime;i++)
            cout<<"* ";
        cout<<"*"<<endl;


        for(int i=q;i>=2;i--)
        {
            a[i]=a[i-1];
            b[i]=b[i-1];
        }
        if(k==1)
        {
            a[1]--;
        }
        if(k==2)
        {
            a[1]++;
        }
        if(k==3)
        {
            b[1]--;
        }
        if(k==4)
        {
            b[1]++;
        }
        if(a[1]<1)
            a[1]=marime;
        if(a[1]>marime)
            a[1]=1;
        if(b[1]<1)
            b[1]=marime;
        if(b[1]>marime)
            b[1]=1;
        for(int i=2;i<=q;i++)
            if(a[1]==a[i] && b[1]==b[i])
                game_open=0;

        Sleep(1000-level);
        system("CLS");

    }

}
int main()
{
    // Constructs the new thread and runs it. Does not block execution.
    ifstream fin("scor.in");
    fin>>max_score;
    fin.close();

    cout<<"SELECTEAZA NIVELUL(0-1000) " ;
    cin>>level;
    cout<<endl;
    cout<<"SELECTEAZA MARIME TERENULUI DE JOC (3-50) " ;
    cin>>marime;
    Sleep(500);
    system("CLS");
    thread t1(task1);
    thread t2(task2);

    // Do other things...
    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
    while(game_open)
    {

    }
    keybd_event(VkKeyScan('A'),0x9e,0 , 0); // ‘A’ Press
    keybd_event(VkKeyScan('A'),0x9e, KEYEVENTF_KEYUP,0); // ‘A’ Release
    t1.join();
    t2.join();
    if(q-2>max_score)
        max_score=q-2;
    ofstream fout("scor.in");
    fout.close();
    fout.open("scor.in", ofstream::out | ofstream::trunc);
    fout<<max_score;
cout<<"  _______      ___      .___  ___.  _______      ______   ____    ____  _______ .______ \n"
       "/  _____|     /   \\     |   \\/   | |   ____|    /  __  \\  \\   \\  /   / |   ____||   _  \     \n"
       "|  |  __     /  ^  \\    |  \\  /  | |  |__      |  |  |  |  \\   \\/   /  |  |__   |  |_)  |   \n"
       "|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|     |  |  |  |   \\      /   |   __|  |      /     \n"
       "|  |__| |  /  _____  \\  |  |  |  | |  |____    |  `--'  |    \\    /    |  |____ |  |\\  \\----.\n"
       " \\______| /__/     \\__\\ |__|  |__| |_______|    \\______/      \\__/     |_______|| _| '._____| \n";
    Sleep(2000);

}
