#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <conio.h>

using namespace std;

    int wielkosc=20;
    int x,y; //pozycja kurczaka

//losowanie pozycji kurczaka
int los_chicken()
{
    x=rand()%wielkosc;
    y=0;

    int chickenX=x;
    int chickenY=y;
}

int main()
{
    srand(time(NULL));
    los_chicken();
    char plansza[wielkosc][wielkosc];
    int X=(20/2),Y=(20-2); //pojazd
    char klawisz;
    int xX[35], yY[35]; //pocisk
    int z=0; //licznik pociskow
    int b=0; //znacznik
    int wynik=0;
    int OBN=0; //Obni?anie sie przeciwnikow - licznik
    int zycie=3; //ilooa ?ya
    int H=1; //licznik do szybkosci
    int szybkosc=60;

//czyszczenie planszy
    for(int i=0;i<wielkosc;i++)
    {
            for(int j=0;j<wielkosc;j++)
                {
                    plansza[i][j]=' ';
                }
    }
//czyszczenie tablicy pociskow
    for(int i=0;i<35;i++)
    {
        xX[i]=99999;
        yY[i]=99999;
    }

//rysowanie mapy
    for(;;)
    {
        for(int i=0;i<wielkosc;i++)
        {
            for(int j=0;j<wielkosc-2;j++)
            {
                plansza[i][j]=' ';
            }
    }

        b=0;
        //poruszanie sie pocisku
        for(int i=0;i<35;i++)
            {
                if(yY[i]<99999)
                {
                    if(yY[i]>0)yY[i]--;
                    else {
						yY[i]=99999; xX[i]=99999;
					}
                }
            }

         if(kbhit())
      {
        klawisz=getch();
        if(klawisz==224)klawisz+=getch();
        if(klawisz==0)klawisz-=getch();
    plansza[X][Y]=' ';
    if ((klawisz==77)&&(X<wielkosc-1))X++;
    if ((klawisz==75)&&(X>0))X--;
    plansza[X][Y]=198;

        if(klawisz==72)
        {
            xX[z]=X; yY[z]=Y-1;
            plansza[xX[z]][yY[z]]=33;
            if(z==35)z=0;else z++;
            }
        }
        if(kbhit())
      {
        klawisz=getch();
        if(klawisz==224)klawisz+=getch();
        if(klawisz==0)klawisz-=getch();
    plansza[X][Y]=' ';
    if ((klawisz==77)&&(X<wielkosc-1))X++;
    if ((klawisz==75)&&(X>0))X--;
    plansza[X][Y]=198;

        if(klawisz==72)
        {
            xX[z]=X; yY[z]=Y-1;
            plansza[xX[z]][yY[z]]=33;
            if(z==35)z=0;else z++;
            }
        }

    //tracenie ?ycia
    if(y>17){zycie--; los_chicken();
        }

    plansza[x][y]='X';
    plansza[X][Y]=198;

    cout << char(201);
    for(int i=0;i<wielkosc;i++){cout << char(205);}
    cout << char(187)<<endl;
    for(int i=0;i<(wielkosc);i++)
        {cout << char(186);
        for(int j=0;j<wielkosc;j++)
            {
                for(int k=0;k<35;k++)
                {
                    if((j==xX[k])&&(i==yY[k]))
                        {if(plansza[xX[k]][yY[k]]=='X'){plansza[xX[k]][yY[k]]=207;los_chicken();wynik++;xX[k]=99999;yY[k]=99999;}
                        else if(plansza[xX[k]][yY[k]+1]=='X'){plansza[xX[k]][yY[k]-1]=207;los_chicken();wynik++;xX[k]=99999;yY[k]=99999;}
                        else plansza[xX[k]][yY[k]]=33;}
                    }
                cout<<plansza[j][i];
            }
        cout << char(186)<<endl;
        }
    cout << char(200);
    for(int i=0;i<wielkosc;i++){cout << char(205);}
    cout << char(188);

    cout<<endl<<"          wynik:"<<wynik;
    cout<<endl<<"          zycie:"<<zycie;
    cout<<endl<<endl;
    cout<<" Sterowanie strzalkami";


    // Testowe pozycje
    /*for(int i=0;i<35;i++)
        {
            if(xX[i]<99999)cout<<endl<<"            "<<i<<" x:"<<xX[i]<<" y:"<<yY[i];
        }
    cout<<endl<<"      chicken x:"<<x<<" y:"<<y;
    cout<<endl<<"       pojazd x:"<<X<<" y:"<<Y;
    cout<<endl<<"              z:"<<z;
    cout<<endl<<"              szybkosc:"<<szybkosc;
    */

    //Obni?anie sie przeciwników;
    if(OBN>2) {y++; OBN=0;}
    OBN++;

    //Warunek konca gry
    if(zycie==0){
    system("CLS");
    cout<<"KONIEC GRY!!!"<<endl<<"Twoj wynik:"<<wynik;
    Sleep(10000);
    system("CLS");
    zycie=3;}

    //Przyspieszanie gry
    if((wynik==5*H)&&(szybkosc>14)){szybkosc=szybkosc-5;H++;}

    Sleep(szybkosc);
    system("CLS");
    }

    return 0;
}

