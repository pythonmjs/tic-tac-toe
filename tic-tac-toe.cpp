#include<iostream>
#include<windows.h>
using namespace std;

char mattrix[3][3];
int t=0,k=0,a[10],p;
int t1=0,k1=0,a1[10],p1;
char b[3][3]={'a'};
char c[3][3]={'a'};

class tictactoe
        {
                 public:

                            void mattrix1()
                                    {

                                        cout<<" ==================================================\n";
                                        cout<<"|                 TIC TAC TOE GAME                 |\n";
                                        cout<<" ==================================================\n";
                                        int m1[3][3],i,j,k=1;
                                        for(i=0;i<3;i++)
                                        {
                                            for(j=0;j<3;j++)
                                            {
                                                m1[i][j]=k;
                                                k++;
                                            }
                                        }

                                            for(i=0;i<3;i++)
                                            {
                                                cout<<" "<< m1[i][0]<<"   |  "<< m1[i][1]<<"   |  "<< m1[i][2];
                                                if(i!=2)
                                                cout<<"\n-----|------|-----\n";
                                            }
                                            cout<<"\n";

                                        cout<<"\n-------------------------------------------------\n";
                                    }


                            void initial_mattrix()
                                    {
                                        int i,j;
                                        for(i=0;i<3;i++)
                                        {
                                            for(j=0;j<3;j++)
                                                mattrix[i][j]=' ';
                                        }
                                    }


                            void disp_matrix()
                                    {
                                        int i;
                                        cout<<"\n";
                                        for(i=0;i<3;i++)
                                            {
                                                cout<<" "<<mattrix[i][0]<<"   |  "<<mattrix[i][1]<<"   |  "<<mattrix[i][2];
                                                if(i!=2)

                                                    cout<<"\n-----|------|-----\n";
                                            }
                                            cout<<"\n";
                                    }

                            char check(void)
                                    {
                                      int i;

                                      for(i=0; i<3; i++)  /* check rows */
                                        if(mattrix[i][0]==mattrix[i][1] &&
                                           mattrix[i][0]==mattrix[i][2]) return mattrix[i][0];

                                      for(i=0; i<3; i++)  /* check columns */
                                        if(mattrix[0][i]==mattrix[1][i] &&
                                           mattrix[0][i]==mattrix[2][i]) return mattrix[0][i];

                                      /* test diagonals */
                                      if(mattrix[0][0]==mattrix[1][1] &&
                                         mattrix[1][1]==mattrix[2][2])
                                           return mattrix[0][0];

                                      if(mattrix[0][2]==mattrix[1][1] &&
                                         mattrix[1][1]==mattrix[2][0])
                                           return mattrix[0][2];

                                         return ' ';
                                    }
                            int draw(void)
                                    {
                                        int i,j,count=0;

                                        for(i=0;i<3;i++)
                                         {
                                             if(mattrix[i][0]!=' ' && mattrix[i][1]!=' ' && mattrix[i][2]!=' ')
                                                count++;
                                         }

                                         if(count==3)
                                            return 3;
                                    }
        };

class computer_vs_player : public tictactoe

        {

                 public:

                            void position()
                                    {
                                            int p,i,j;

                                            cout<<"\nYOUR TURN -- enter position of your 'O' :";
                                            n:

                                                try
                                                    {
                                                        cin>>p;
                                                        if(p<1 || p>9)
                                                            throw 1.23;
                                                    }
                                                catch(float x)
                                                    {
                                                        cout<<"ENTER PROPER POSITION:";
                                                            goto n;
                                                    }

                                            switch(p)
                                            {
                                            case 1:
                                               {  mattrix[0][0]='O'; break; }
                                            case 2:
                                               {  mattrix[0][1]='O'; break; }
                                            case 3:
                                               {  mattrix[0][2]='O'; break; }
                                            case 4:
                                               {  mattrix[1][0]='O'; break; }
                                            case 5:
                                               {  mattrix[1][1]='O'; break; }
                                            case 6:
                                               {  mattrix[1][2]='O'; break; }
                                            case 7:
                                               {  mattrix[2][0]='O'; break; }
                                            case 8:
                                               {  mattrix[2][1]='O'; break; }
                                            case 9:
                                               {  mattrix[2][2]='O'; break; }
                                            }

                                            for(i=0;i<3;i++)    //invalid choice--where computer choice
                                            {
                                               for(j=0;j<3;j++)
                                               {
                                                   if(mattrix[i][j]==b[i][j])
                                                   {
                                                       cout<<"INVALID CHOICE --PLEASE ENTER PROPER POSITION:";
                                                       b[i][j]='a';

                                                       mattrix[i][j]='X';
                                                       goto n;
                                                   }

                                               }
                                            }

                                            a[k]=p;

                                            if(t!=0)                 //Invalid choice where--our choice
                                            {
                                                for(i=0;i<t;i++)
                                                {
                                                  if(a[i]==a[t])
                                                  {
                                                    cout<<"INVALID CHOICE --PLEASE ENTER PROPER POSITION:";
                                                    goto n;
                                                  }
                                                }
                                            }
                                           k++;
                                           t++;

                                    }

                            void computer_turn()
                                    {
                                          int i,j;

                                          for(i=0;i<3;i++)
                                          {
                                             if(mattrix[i][0]==' ')
                                             {
                                                mattrix[i][0]='X';
                                                b[i][0]='O';
                                                break;
                                             }
                                             else if(mattrix[i][1]==' ')
                                             {
                                                mattrix[i][1]='X';
                                                 b[i][1]='O';
                                                break;
                                             }
                                             else if(mattrix[i][2]==' ')
                                             {
                                                mattrix[i][2]='X';
                                                 b[i][2]='O';
                                                break;
                                             }

                                     }
                                     p=draw();
                                    }

                            void player1()
                                    {
                                   char end=' ';
                                   initial_mattrix();
                                    do
                                    {
                                      position();
                                      end=check();
                                      if(end!=' ')goto q;

                                       computer_turn();
                                    if(p==3)
                                        {break;}

                                       end=check();
                                       if(end!=' ')goto q;
                                        system("cls");
                                        mattrix1();
                                        disp_matrix();
                                        //cout<<"\n-------------------------------------------------\n";

                                    }
                                    while(end==' ');

                                   q:
                                    system("cls");
                                    mattrix1();
                                    disp_matrix();
                                    if(p==3)
                                        {cout<<"\n---------------------DRAW------------------------\n";}

                                     if(end=='X')
                                        {cout<<"\n-----------------COMPUTER WIN--------------------\n";}
                                     else if(end=='O')
                                        {cout<<"\n--------------------YOU WIN----------------------\n";}
                                }
        };


class p1_vs_p2 : public tictactoe

        {

                 public:

                            void position1()
                                    {
                                        int i,j,p;

                                        cout<<"\nPLAYER 1 -- enter position of 'O' :";
                                        n:
                                        try
                                            {
                                                cin>>p;
                                                if(p<1 || p>9)
                                                    throw p;
                                            }
                                        catch(int x)
                                            {
                                                cout<<"ENTER PROPER POSITION:";
                                                goto n;
                                            }
                                try
                                    {
                                        switch(p)
                                        {
                                        case  1:
                                           {  mattrix[0][0]='O'; c[0][0]='X'; break; }
                                        case  2:
                                           {  mattrix[0][1]='O'; c[0][1]='X'; break; }
                                        case  3:
                                           {  mattrix[0][2]='O'; c[0][2]='X'; break; }
                                        case  4:
                                           {  mattrix[1][0]='O'; c[1][0]='X'; break; }
                                        case  5:
                                           {  mattrix[1][1]='O'; c[1][1]='X'; break; }
                                        case 6:
                                           {  mattrix[1][2]='O'; c[1][2]='X'; break; }
                                        case 7:
                                           {  mattrix[2][0]='O'; c[2][0]='X'; break; }
                                        case 8:
                                           {  mattrix[2][1]='O'; c[2][1]='X'; break; }
                                        case 9:
                                           {  mattrix[2][2]='O'; c[2][2]='X'; break; }
                                        }

                                        for(i=0;i<3;i++)    //invalid choice--where player 2 choice
                                        {
                                           for(j=0;j<3;j++)
                                           {
                                               if(mattrix[i][j]==b[i][j])
                                               {
                                                   throw 3;
                                               }

                                           }
                                        }

                                         a[k]=p;

                                        if(t!=0)                 //Invalid choice where--player 1 choice
                                        {
                                            for(i=0;i<t;i++)
                                            {
                                              if(a[i]==a[t])
                                              {
                                                throw 4.8;
                                              }
                                            }
                                        }
                                       k++;
                                       t++;
                                    }

                                    catch(int q)
                                        {
                                            cout<<"INVALID CHOICE --PLEASE ENTER PROPER POSITION:";
                                            mattrix[i][j]='X';
                                            goto n;
                                        }
                                    catch(double s)
                                    {
                                        cout<<"INVALID CHOICE --PLEASE ENTER PROPER POSITION:";
                                        goto n;
                                    }

                                       system("cls");
                                       mattrix1();
                                       disp_matrix();
                                       p1=draw();

                                    }

                            void position2()
                                    {
                                            int p1,i,j;

                                            cout<<"\nPLAYER 2 -- enter position of 'X' :";
                                            n:
                                            cin>>p1;
                                            if(p1<1 || p1>9)
                                                {cout<<"ENTER PROPER POSITION:";
                                                goto n;}

                                            switch(p1)
                                            {
                                            case 1:
                                               {
                                                   if(mattrix[0][0]==' ')
                                                    {mattrix[0][0]='X';
                                                     b[0][0]='O';}
                                                   else
                                                    {cout<<"ENTER PROPER POSITION:";
                                                    goto n;}
                                                    break; }
                                            case 2:
                                               {
                                                    if(mattrix[0][1]==' ')
                                                    {mattrix[0][1]='X';
                                                    b[0][1]='O';}
                                                   else
                                                    {cout<<"ENTER PROPER POSITION:";
                                                    goto n;}
                                                    break;
                                               }
                                            case 3:
                                               {   if(mattrix[0][2]==' ')
                                                    {mattrix[0][2]='X';
                                                      b[0][2]='O';}
                                                   else
                                                    {cout<<"ENTER PROPER POSITION:";
                                                    goto n;}
                                                    break;
                                               }
                                            case 4:
                                               {  if(mattrix[1][0]==' ')
                                                    {mattrix[1][0]='X';
                                                     b[1][0]='O';}
                                                   else
                                                    {cout<<"ENTER PROPER POSITION:";
                                                    goto n;}
                                                    break; }
                                            case 5:
                                               {  if(mattrix[1][1]==' ')
                                                    {mattrix[1][1]='X';
                                                     b[1][1]='O';}
                                                   else
                                                    {cout<<"ENTER PROPER POSITION:";
                                                    goto n;}
                                                    break; }
                                            case 6:
                                               {  if(mattrix[1][2]==' ')
                                                    {mattrix[1][2]='X';
                                                     b[1][2]='O';}
                                                   else
                                                    {cout<<"ENTER PROPER POSITION:";
                                                    goto n;}
                                                    break; }
                                            case 7:
                                               {  if(mattrix[2][0]==' ')
                                                    {mattrix[2][0]='X';
                                                     b[2][0]='O';}
                                                   else
                                                    {cout<<"ENTER PROPER POSITION:";
                                                    goto n;}
                                                    break; }
                                            case 8:
                                               {  if(mattrix[2][1]==' ')
                                                    {mattrix[2][1]='X';
                                                     b[2][1]='O';}
                                                   else
                                                    {cout<<"ENTER PROPER POSITION:";
                                                    goto n;}
                                                    break; }
                                            case 9:
                                               {  if(mattrix[2][2]==' ')
                                                    {mattrix[2][2]='X';
                                                     b[2][2]='O';}
                                                   else
                                                    {cout<<"ENTER PROPER POSITION:";
                                                    goto n;}
                                                    break; }
                                            }



                                            a1[k1]=p1;

                                            if(t1!=0)                 //Invalid choice where--player 2 choice
                                            {
                                                for(i=0;i<t1;i++)
                                                {
                                                  if(a1[i]==a1[t1])
                                                  {
                                                    cout<<"INVALID CHOICE --PLEASE ENTER PROPER POSITION!!:";
                                                    goto n;
                                                  }
                                                }
                                            }
                                           k1++;
                                           t1++;

                                    }

                            void player2(void)
                                    {

                                            char end=' ';
                                            initial_mattrix();
                                            do
                                            {
                                              position1();

                                              end=check();
                                              if(end!=' ')goto q;
                                               if(p1==3)
                                                {cout<<"\n----------------------DRAW----------------------\n";break;}

                                               position2();

                                               end=check();
                                               if(end!=' ')goto q;
                                               system("cls");
                                               mattrix1();
                                               disp_matrix();
                                            }
                                            while(end==' ');

                                           q:
                                             system("cls");
                                             mattrix1();
                                             disp_matrix();

                                             if(end=='X')
                                                {cout<<"\n-------------------PLAYER 2 WIN---------------------\n";}
                                             else if(end=='O')
                                                {cout<<"\n-------------------PLAYER 1 WIN---------------------\n";}
                                    }
        };

int  main()
        {

                computer_vs_player obj;
                p1_vs_p2 obj1;
                int d,choice;

                obj.mattrix1();

                cout<<"\n1) PLAYER VS COMPUTER   \n";
                cout<<"\n2) PLAYER 1 VS PLAYER 2 \n";
                cout<<"\n3) EXIT                 \n";
                next:
                cin>>choice;
                if(choice < 1 || choice > 3 )
                   {
                    cout<<"INVALID CHOICE--CHOOSE PROPER:";
                    goto next;
                   }

                switch(choice)
                {
                  case 1:
                  {
                    cout<<"\n-------------------------------------------------\n";
                    obj.player1();
                    break;
                  }
                  case 2:
                  {
                    cout<<"\n-------------------------------------------------\n";
                    obj1.player2();
                    break;
                  }
                  case 3:
                  {
                    cout<<"\n-------------------------------------------------\n";
                    ;
                  }
                }

                return 0;
        }

















