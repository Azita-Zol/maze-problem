//
//  main.c
//  maze
//
//  Created by Azita on 2018-07-20.
//  Copyright (c) 2018 azita. All rights reserved.
//

#include <stdio.h>

#define true 1
#define false 0

int isPathOpen(int maze[10][10], int x, int y)  // Is the path open at point (x,y) to continue?
{
    if((maze[x][y] == 0 ) &&x >= 0 && x < 10 && y >= 0 && y < 10 )
        return true;
    
    return false;
}


// A recursive function for solving maze maze
int Maze(int maze[10][10], int x, int y, int sol[10][10], int vmat[10][10])
{
    
    if(x == 9 && y == 9)  // reach the destination
    {
        sol[x][y] = 0;
        return true;
    }
    
    // Check if maze[x][y] is valid
    if(isPathOpen(maze, x, y) == true)
    {
        // mark x,y as part of solution path
        sol[x][y] = 0;
        vmat[x][y]=1; // mark x,y as visited
        
        
        // Move down (for the same column y, )
        if(vmat[x+1][y]==0) // if a new point is not visited yet
            if (Maze(maze, x+1, y, sol, vmat) == true)
                return true;
        
        // Move right
        if(vmat[x][y+1]==0)
            if (Maze(maze, x, y+1, sol, vmat) == true)
                return true;
        
        // Move left
        if(vmat[x][y-1]==0)
            if (Maze(maze, x, y-1, sol, vmat) == true)
                return true;
        
        // Move up
        if(vmat[x-1][y]==0)
            if (Maze(maze, x-1, y, sol, vmat) == true)
                return true;
        
        
        sol[x][y] = 1;  // unmark x,y as part of solution path
        
        return false;
    }
    
    return false;
}

int main()
{
    // zero means the path is open, otherwise the path is closed
    int m[10][10]=
    {   0,    1,    1,    0,    1,    1,    1,    1,    0,    1,
        0,    1,    0,    0,    0,    0,    1,    1,    1,    1,
        0,    1,    0,    0,    1,    0,    1,    1,    1,    1,
        0,    0,    0,    1,    1,    0,    1,    1,    1,    1,
        0,    1,    1,    1,    0,    0,    1,    0,    0,    1,
        1,    1,    1,    1,    0,    1,    1,    0,    0,    1,
        1,    1,    0,    1,    0,    0,    0,    0,    0,    0,
        0,    1,    0,    0,    1,    1,    1,    1,    0,    1,
        0,    1,    1,    0,    1,    1,    1,    1,    0,    1,
        0,    1,    1,    1,    1,    1,    1,    1,    0,    0
    };
    
    
    int sol[10][10], vmat[10][10];  /* sol is a matrix of solution, and vmat (visited matrix) is a matrix that shows a point (x,y) is visited or not */
    
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
        {
            vmat[i][j]=0;          //initiated to zero (zero means it is not visited)
            sol[i][j]=1;
        }
    
    // Solving the Maze problem using Backtracking (by calling recursive function)

    if(Maze(m, 0, 0, sol,vmat) == false)
        printf("Path doesn't exist");
    else
      for (int i = 0; i < 10; i++)
      {
        for (int j = 0; j < 10; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
      }

    return 0;
}