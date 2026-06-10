#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void clearCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle(int x,int y,int width,int height)
{
    for(int i=x;i<x+height;i++)
    {
        for(int j=y;j<y+width;j++)
        {
            canvas[i][j]='*';
        }
    }
}
void drawLine(int row,int startCol,int endCol)
{
    for(int i=startCol;i<=endCol;i++)
    {
        canvas[row][i]='*';
    }
}
void drawTriangle(int x,int y,int height)
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<=i;j++)
        {
            canvas[x+i][y+j]='*';
        }
    }
}
void drawCircle(int cx,int cy,int r)
{
    for(int x=0;x<ROWS;x++)
    {
        for(int y=0;y<COLS;y++)
        {
            int d=(x-cx)*(x-cx)+(y-cy)*(y-cy);

            if(d>=r*r-r && d<=r*r+r)
            {
                canvas[x][y]='*';
            }
        }
    }
}

int main()
{
    clearCanvas();
    drawRectangle(2,5,10,4);
    drawLine(10,5,25);
    drawTriangle(12,5,5);
    drawCircle(10,30,4);
    
    displayCanvas();
    return 0;
}
