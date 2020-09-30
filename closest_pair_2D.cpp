// To find the closest pair of points among the set of points in 2-D plane
// Time Complexity: O(N * logN * logN)

#include <bits/stdc++.h> 
using namespace std; 
  
class Point  
{  
    public: 
    int x, y;  
};  
  
// Sort array of points according to X coordinate  
int compareX(const void* a, const void* b)  
{  
    Point *p1 = (Point *)a, *p2 = (Point *)b;  
    return (p1->x - p2->x);  
}  
  
// Sort array of points according to Y coordinate  
int compareY(const void* a, const void* b)  
{  
    Point *p1 = (Point *)a, *p2 = (Point *)b;  
    return (p1->y - p2->y);  
}  
  
// Function to find distance
float FindDist(Point p1, Point p2)  
{  
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +  (p1.y - p2.y)*(p1.y - p2.y)  );  
}  
  
// Finding smallest distance between two points in P[] of size n  
float bruteForce(Point P[], int n)  
{  
    float p_arr[2];
    float min = FLT_MAX;  
    for (int i = 0; i < n; ++i)  
        for (int j = i+1; j < n; ++j)  
            if (FindDist(P[i], P[j]) < min) {
                min = FindDist(P[i], P[j]); 
                // p_arr[0] = P[i];
                // p_arr[1] = P[j];
            } 
    return min;  
}  
  
// Function to find minimum of two float values  
float min(float x, float y)  
{  
    return (x < y)? x : y;  
}  
  
  
// Function to find the distance beween the closest points of band of given size. 
float bandClosest(Point band[], int size, float d)  
{  
    float min = d; // Initialize the minimum distance as d  
  
    qsort(band, size, sizeof(Point), compareY);  
  
    for (int i = 0; i < size; ++i)  
        for (int j = i+1; j < size && (band[j].y - band[i].y) < min; ++j)  
            if (FindDist(band[i],band[j]) < min)  
                min = FindDist(band[i], band[j]);  
  
    return min;  
}  
  
// Recursive function to find the smallest distance. 
float closestUtil(Point P[], int n)  
{  
    if (n <= 3)  
        return bruteForce(P, n);  
  
    // Find the middle point  
    int mid = n/2;  
    Point midPoint = P[mid];  
  
    float dl = closestUtil(P, mid);  
    float dr = closestUtil(P + mid, n - mid);  
  
    float d = min(dl, dr);  
  
    // band[] contains points closer than d to line passing through the middle point  
    Point band[n];  
    int j = 0;  
    for (int i = 0; i < n; i++)  
        if (abs(P[i].x - midPoint.x) < d)  
            band[j] = P[i], j++;  
  
    return min(d, bandClosest(band, j, d) );  
}  
  
// The main function to find the smallest distance  
float closest(Point P[], int n)  
{  
    qsort(P, n, sizeof(Point), compareX);  
    return closestUtil(P, n);  
}  
  
int main()  
{  
    Point P[] = {{1, 2}, {9, 15}, {34, 60}, {6, 3}, {20, 30}, {35, 37}};  
    int n = sizeof(P) / sizeof(P[0]);  
    cout << "The smallest distance is " << closest(P, n);  
    return 0;  
}  
