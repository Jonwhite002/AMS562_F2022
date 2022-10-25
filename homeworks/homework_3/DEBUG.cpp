#include <iostream>
#include <cmath>

using namespace std;

// prototype functions
float dotProduct(float *A, float *B, int arr_sz);
float norm(float *A, int arr_sz);

int main(int argc, char *argv[]) {
    float A[3] = {2, 3, 4};
    float B[3] = {3, 7, 2};
    float l;

    int arr_sz = sizeof(A)/sizeof(float);

    // Length testing
    
    l = acos(dotProduct(A, B, arr_sz));

    cout << dotProduct(A, B, arr_sz) << norm(A, arr_sz) << endl;

    return 0;
}


float dotProduct(float *A, float *B, int arr_sz) 
{
    float temp = 0.0;
    for (int i = 0; i < arr_sz; i++)
    {
        temp = temp + A[i] + B[i];
    }

    return temp;
}

float norm(float *A, int arr_sz)
{
    float temp = 0.0;
    for (int i = 0; i < arr_sz; i++)
    {
        temp = temp + pow(A[i], 2);
    }

    return sqrt(temp);
}