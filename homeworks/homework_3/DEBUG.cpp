#include <iostream>
#include <cmath>

using namespace std;

// prototype functions
float dotProduct(float *A, float *B, int arr_sz);
void unitVec(float *A, float *vec, int arr_sz);

int main(int argc, char *argv[]) {
    // Create meta data
    int N = 100;
    float *data = new float [N];

    cout << sizeof(data)/sizeof(float) << endl;

    // Relax memory
    delete[] data;

    return 0;
}


float dotProduct(float *A, float *B, int arr_sz) 
{
    float temp = 0.0;
    for (int i = 0; i < arr_sz; i++)
    {
        temp = temp + A[i]*B[i];
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