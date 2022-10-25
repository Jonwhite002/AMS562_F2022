#include <cmath>
#include <cstdlib>
#include <ctime>  // for trigger the seed of random number generator
#include <iostream>

static void genPointsOnUnitSphere(const int N, float *x, float *y, float *z);
float dotProduct(float *A, float *B, int arr_sz);
void unitVec(float *A, float *vec, int arr_sz);

int main(int argc, char *argv[]) {
  // get the size of N
  int N = std::atof(argv[1]);

  // sanity check
  if (argc < 2 || std::isnan(N))
  {
    std::cerr << "ERROR: The value of N is either missing or is not a number!" << std::endl;
    std::exit(1);
  } else if (N <= 0.0) {
    std::cerr << "ERROR: Please choose a value of N that is greater than 0!" << std::endl;
    std::exit(1);
  } else {

    // allocate memory for x, y, z
    float *x = new float [N], *y = new float [N], *z = new float [N];

    genPointsOnUnitSphere(N, x, y, z);

    // determine the extreme arc lengths
    float length, vec[N][3], n1[3], n2[3];

    // create vectors with x y & z components
    for (int i = 0; i < N; i++)
    {
      vec[i][0] = x[i];
      vec[i][1] = y[i];
      vec[i][2] = z[i];
    }

    // Find arc lengths of different points
    // for (int i = 1; i < N; i++)
    // {
    //   unitVec(vec[0], n1, 3); unitVec(vec[i], n2, 3);
    //   length = acos(dotProduct(n1, n2, 3));
    //   std::cout << "Length btwn points 0 and " << i << ": " << length << std::endl;
    // }

    // Debug print out x y & z values
    for (int i = 0; i < N; i++)
    {
      std::cout << "Vector " << i << ":" << x[i] << " " << y[i] << " " << z[i] << std::endl;
    }

    // relax memory
    delete[] x; delete[] y; delete[] z;
  }

  return 0;
}

// black-box function to generate a collection of random points
void genPointsOnUnitSphere(const int N, float *x, float *y, float *z) {
  if (x == nullptr || y == nullptr || z == nullptr || N <= 0) {
    std::cerr << "invalid pointers or size, aborting...\n";
    std::exit(1);
  }
  std::srand(std::time(0));  // trigger the seed
  const int BD = 10000000, BD2 = 2 * BD;
  const float inv_bd = 1.0f / BD;  // not integer division
  for (int i = 0; i < N; ++i) {
    x[i] = (std::rand() % BD2 - BD) * inv_bd;
    y[i] = (std::rand() % BD2 - BD) * inv_bd;
    z[i] = (std::rand() % BD2 - BD) * inv_bd;
    const float len = std::sqrt(x[i] * x[i] + y[i] * y[i] + z[i] * z[i]);
    if (len > 1e-5f) {
      // project on to unit sphere
      x[i] /= len;
      y[i] /= len;
      z[i] /= len;
    } else {
      // too close to zero
      // directly set the point to be (1,0,0)
      x[i] = 1.0f;
      y[i] = z[i] = 0.0f;
    }
  }
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