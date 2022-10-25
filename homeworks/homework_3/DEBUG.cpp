#include <iostream>
#include <cmath>

using namespace std;

// prototype functions
float dotProduct(float *A, float *B, int arr_sz);
void unitVec(float *A, float *vec, int arr_sz);

int main(int argc, char *argv[]) {
    float A[3] = {2, 3, 4};
    float B[3] = {3, 7, 2};
    float n1[3], n2[3];
    float l;

    int arr_sz = sizeof(A)/sizeof(float);

    // Length testing
    unitVec(A, n1, 3);
    unitVec(B, n2, 3);
    l = acos(dotProduct(n1, n2, arr_sz));

    cout << dotProduct(n1, n2, arr_sz) << endl;

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

void unitVec(float *A, float *vec, int arr_sz)
{
    // Find the norm
    float norm, temp = 0.0;
    for (int i = 0; i < arr_sz; i++)
    {
        temp = temp + pow(A[i], 2);
    }
    norm = sqrt(temp);

    // Determine the unit vector
    for (int i = 0; i < arr_sz; i++)
    {
        vec[i] = A[i]/norm;
    }
}