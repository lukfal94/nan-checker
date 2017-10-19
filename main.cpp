#include <climits>
#include <stdio.h>
#include <vector>
#include <cmath>

int main(void)
{
  FILE* ofp = fopen("output.txt", "w");
  std::vector<unsigned int> nan_vals;

  for(unsigned int i = 0; i < UINT_MAX; i++)
  {
    float *tmp = 0;

    // Reinterpret the value of i as a float
    tmp = (float*) reinterpret_cast<float*>(&i);

    // Test for NaN
    if(std::isnan(*tmp))
    {
      // Record the value that was NaN
      nan_vals.push_back(i);
    }
  }

  printf("Found %d NaN values:\n", (int) nan_vals.size());
  for(int i = 0; i < nan_vals.size(); i++)
  {
    fprintf(ofp, "0x%08x ", nan_vals[i]);
  }

  return 0;
}
