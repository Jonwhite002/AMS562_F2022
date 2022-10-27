#include <iostream>
#include <cmath>

// prototype functions
float dotProduct(float *A, float *B, int arr_sz);
void unitVec(float *A, float *vec, int arr_sz);

int main(int argc, char *argv[]) {
    // Create meta data
    int N = std::atoi(argv[1]);
    float A[3] = {3,6,9};
    float B[3] = {7,2,4};
    float len, n1[3], n2[3];

    unitVec(A, n1, 3);

    len = dotProduct(A, B, 3);

    std::cout << n1[0] << " " << n1[1] << " " << n1[2] << std::endl;

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