
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
int main()
{
    int i,j,k,x,y;
    int gd=DETECT,gm;
    int ch1[][10]= { {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,0,0,0,0},
        {1,1,1,1,1,1,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0}
    };


    initgraph(&gd,&gm,"D:\\TC\\BGI");
    setbkcolor(LIGHTGRAY);
    for(k=0; k<4; k++)
    {
        for(i=0; i<10; i++)
        {
            for(j=0; j<10; j++)

            {


                if(ch1[i][j]==1)
                    putpixel(j+250,i+230,RED);

            }

        }
    }
    getch();
    closegraph();
}
