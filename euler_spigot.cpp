/*******************************
*   euler_spigot.cpp
*
*   Print digits of euler's constant e.
*
*   author: Ryan Morehouse
*   license: MIT
*
*******************************/

#include <iostream>
#include <sstream>
#define LIMIT 1000

void error_msg() {
	std::cout << "Usage: ./euler_spigot.o [n]" << std::endl;
	std::cout << "[n] is a positive integer less than 1000\n" << std::endl;
}

int main(int argc, char *argv[]) {
  // user input
  int n;

	// verify arg exist
  if(argc < 2) {
    error_msg();
    return 1;
  }

  // verify arg n is within limits
  std::istringstream ss(argv[1]);
  if (!(ss >> n))
    error_msg();
  else if (n < 1 || n > LIMIT)
    error_msg();

  // initialize processing array
  int a_len = n+2;
  int a[a_len];
  for(int i = 0; i < a_len; i++)
    a[i] = 1;

  // first digit is 2
  std::cout << 2;

  if(n > 1) {
    for(int i = 0; i < n-1; i++) {
      int q = 0;
      // traverse a[] backwards
      for(int j = a_len-1; j > -1; j--) {
        int denom = j+2;
        int nom = (10 * a[j]) + q;
        q = nom / denom;
        int r = nom % denom;
        a[j] = r;
        if(j == 0)
          std::cout << q;
      }
    }
  }

  std::cout << std::endl << std::endl;
  return 0;
}
