#include <iostream>
using namespace std;
#define INT_MAX 1e8

//Author : Daksh Gupta 20103026
//Created at : 29-11-2021 18:21pm
int min(int a, int b){
    return (a<b)? a : b;
}

int main()
{
    cout << "Write the number of vertices n\n";
    int n;
    cin >> n;

    cout << "Which vertex is the starting position? \n(vertices are numbered 1 to n)\n";
    int start;
    cin >> start;
    start--;

    cout << "Give a nXn matrix representing weight of all edges.\nif edge doesn't exist write -1\n";

    int matrix[n][n]; //this represents the cost of going from edge row to column
    int distance[n];  //currently the distance of vertices from start
    bool visited[n];  //have not visited any vertex yet

    //input all weights and set the distance
    for (int i = 0; i < n; i++)
    {

        distance[i] = INT_MAX;
        if (i == start)
        {
            distance[i] = 0;
        }

        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    //find shortest path
    for (int i = 0; i < n-1; i++)
    {
        int vertexToVisitThisTime;

        if (!visited[start])
            vertexToVisitThisTime = start;
        else
        {
            //find minimum value till now in vertices not visited
            int thisVerticeCost = INT_MAX;

            for (int j = 0; j < n; j++)
            {
                if (!visited[j])
                {
                    if (distance[j] < thisVerticeCost)
                    {
                        thisVerticeCost = distance[j];
                        vertexToVisitThisTime = j;
                    }
                }
            }
        }

        //i have found the vertex i will explore this time
        visited[vertexToVisitThisTime]=1; 

        //update all values of his neighbour 
        for (int i=0; i<n; i++){
            if (matrix[vertexToVisitThisTime][i] != -1){
                //set distance of each adjacent to minimum of current abd if thiss path was chosen
                distance[i]=min(distance[i], distance[vertexToVisitThisTime]+matrix[vertexToVisitThisTime][i]);

            }
        }
    }
    cout << "The distance from the starting to i-th vertice is as follows: \n";
    for (int i=0; i<n; i++){
        if (distance[i]==INT_MAX){
            cout << "Vertice: " << i+1 << " is not reachable from start. "<<  endl;
        }else{
            cout << "Vertice: " << i+1 << " Distance from start: "<< distance[i] << endl;
        }
    }
    
}