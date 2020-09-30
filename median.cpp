// Finding median of 2 arrays

#include<bits/stdc++.h>
using namespace std;
 
/* to get median of a sorted array */
int median(int [], int); 
 
int getMedian(int ar1[], 
              int ar2[], int n)
{
    /* return -1 for invalid input */
    if (n <= 0)
        return -1;
    if (n == 1)
        return (ar1[0] + ar2[0]) / 2;
    if (n == 2)
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;
 
    int m1 = median(ar1, n); 
    int m2 = median(ar2, n); 
 
    if (m1 == m2)
        return m1;
 
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n / 2 - 1, 
                             ar2, n - n / 2 + 1);
        return getMedian(ar1 + n / 2, 
                         ar2, n - n / 2);
    }
 
    if (n % 2 == 0)
        return getMedian(ar2 + n / 2 - 1, ar1, n - n / 2 + 1);
    return getMedian(ar2 + n / 2, ar1, n - n / 2);
}
 
/* Function to get median of a sorted array */
int median(int arr[], int n)
{
    if (n % 2 == 0)
        return (arr[n / 2] + 
                arr[n / 2 - 1]) / 2;
    else
        return arr[n / 2];
}
 
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int ar1[n1], ar2[n2];
    for(int i = 0; i < n1; i++)
        cin >> ar1[i];
    for(int i = 0; i < n2; i++)
        cin >> ar2[i];

    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median: "
             << getMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays "of unequal size";
    return 0;
}
