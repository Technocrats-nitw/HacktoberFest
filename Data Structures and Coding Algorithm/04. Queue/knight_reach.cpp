
// Knight Reach Problem without using STL
/*
Find the minimum number of steps for a Knight in a chess board to reach from a source location to destination location.

You have to read the input four numbers :  (sx , sy ) and (dx, dy ) 

Input : 7 0 0 7 

output : 6
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// This point represent a cell in chess
struct point
{
    int x;
    int y;
    int d;
};

// defining structure for Queue
typedef struct queu
{
    int f, r;
    int siz;
    point *elements[1000];
} * que;
// for push operation in queue
void push(que q, point *p)
{
    if ((q->r + 1) % q->siz == q->f)
        cout << "Full\n";
    else
    {
        if (q->f == -1)
        {
            q->f = 0;
            q->r = 0;
        }
        else
            q->r = (q->r + 1) % q->siz;
        q->elements[q->r] = p;
    }
}
// for pop operation in queue
point *pop(que q)
{
    if (q->f == -1)
    {
        point *t = new (point);
        t->x = -1;
        t->y = -1;
        t->d = -1;
        return t;
    }
    point *t = q->elements[q->f];
    if (q->f == q->r)
    {
        q->f = -1;
        q->r = -1;
    }
    else
        q->f = (q->f + 1) % q->siz;
    return t;
}
// This function will check that our knight is inside the chessboard or it has crossed the boundaries
bool check_inside(int x, int y)
{
    if ((x >= 0 && x < 8) && (y >= 0 && y < 8))
        return true;
    return false;
}

// this function check that whether the given cell is visited or not,help in avoiding rechecking
bool not_visited(int a[8][8], int x, int y)
{
    if (a[x][y] == 1)
        return false;
    return true;
}
// THis is the function which will return the number of steps taken to reach the knight to given destination
int steps_taken(int sx, int sy, int dx, int dy)
{

    que q = new (queu);
    q->f = -1;
    q->r = -1;
    q->siz = 100;
    int i, j;
    int xdir[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int ydir[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    int a[8][8];
    // creating a chess board matrix with all value 0 indicating that no cell is visited till now
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            a[i][j] = 0;
    }

    point *p = new (point);
    p->x = sx;
    p->y = sy;
    p->d = 0;
    push(q, p);
    a[sx][sy] = 1;
    while (q->f != -1)
    {
        point *pt = pop(q);
        if (pt->x == dx && pt->y == dy)
        {
            return pt->d;
        }

        for (i = 0; i < 8; i++)
        {
            if (check_inside(pt->x + xdir[i], pt->y + ydir[i]))
            {
                if (not_visited(a, pt->x + xdir[i], pt->y + ydir[i]))  
                {
                    point *temp = new (point);     // temp point is used to create new point
                    temp->d = pt->d + 1;           // new distance
                    temp->x = pt->x + xdir[i];     // new x-coordinate
                    temp->y = pt->y + ydir[i];     // new y-coordinate
                    a[temp->x][temp->y] = 1;        // make it visited
                    push(q, temp);                 // pushing in queue
                }
            }
        }
    }
    return -1;
}

int main()
{

    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    int ans = steps_taken(sx, sy, dx, dy);
    if (ans == -1)
        cout << "Not Possible to reach\n";
    else
        cout << ans << "\n";
}
