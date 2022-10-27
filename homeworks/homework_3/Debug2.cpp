#include <cmath>
#include <cstdlib>
#include <ctime>  // for trigger the seed of random number generator
#include <iostream>

static void genPointsOnUnitSphere(const int N);

int main(int argc, char *argv[]) {
  // parse input argc/argv

  int N = 5;
  // get the size of N

  float *x = nullptr, *y = nullptr, *z = nullptr;

  // allocate memory for x, y, z

  genPointsOnUnitSphere(N);

  // determine the extreme arc lengths

  // relax memory

  return 0;
}

// black-box function to generate a collection of random points
void genPointsOnUnitSphere(const int N) {
  float x, y, z;
  std::srand(std::time(0));  // trigger the seed
  const int BD = 10000000, BD2 = 2 * BD;
  const float inv_bd = 1.0f / BD;  // not integer division
  for (int i = 0; i < N; ++i) {
    x = (std::rand() % BD2 - BD) * inv_bd;
    y = (std::rand() % BD2 - BD) * inv_bd;
    z = (std::rand() % BD2 - BD) * inv_bd;
    const float len = std::sqrt(x * x + y * y + z * z);
    if (len > 1e-5f) {
      // project on to unit sphere
      x /= len; std::cout << x << " ";
      y /= len; std::cout << y << " ";
      z /= len; std::cout << z << std::endl;
    } else {
      // too close to zero
      // directly set the point to be (1,0,0)
      x = 1.0f;
      y = z = 0.0f;
    }
  }
}
