#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#ifdef PART1
int main() {
  std::string buffer;
  unsigned long total = 0;

  do {
    std::getline(std::cin, buffer);

    char n[3] = "\0\0";

    for (int i = 0; !buffer.empty() && std::strlen(n) < 2; i++) {
      size_t leni = buffer.length() - i - 1;
      if (n[0] == 0) {
        if ('1' <= buffer[i] && buffer[i] <= '9') {
          n[0] = buffer[i];
        }
      }

      if (n[1] == 0) {
        if ('1' <= buffer[leni] && buffer[leni] <= '9') {
          n[1] = buffer[leni];
        }
      }
    }

    if (std::strlen(n) == 2)
      total += (n[0] - '0') * 10 + n[1] - '0';
  } while (!buffer.empty());

  printf("%lu\n", total);

  return 0;
}
#endif


#ifdef PART2
int main(void) {

}
#endif
