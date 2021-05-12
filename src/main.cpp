#include "tbb/parallel_for.h"
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  auto values = std::vector<double>(100000);
  tbb::parallel_for(tbb::blocked_range<int>(0, values.size()),
                    [&](tbb::blocked_range<int> r) {
                      for (int i = r.begin(); i < r.end(); ++i) {
                        values[i] = std::sin(i * 0.001);
                      }
                    });
  std::cout << "Hello from my programme" << std::endl;
  return 0;
}