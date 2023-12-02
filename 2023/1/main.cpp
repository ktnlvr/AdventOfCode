#include <algorithm>
#include <cstring>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>

#ifdef PART2

std::optional<std::pair<size_t, char>> slice_matches_words(const char *begin,
                                                           const char *slice) {
  static constexpr std::pair<const char *, char> words[10] = {
      {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4}, {"five", 5},
      {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10}};
  if (begin > slice) {
    return std::nullopt;
  }

  for (auto [word, ch] : words) {
    auto l = std::strlen(word);
    if (!std::strncmp(slice, word, l))
      return std::make_pair(std::strlen(word), ch + '0');
  }

  return std::nullopt;
}

#endif

int main() {
  std::string buffer;
  unsigned long total = 0;

  do {
    std::getline(std::cin, buffer);

    char n[3] = "\0\0";

    for (int i = 0, j = 0; !buffer.empty() && std::strlen(n) < 2; i++, j++) {
      size_t leni = buffer.length() - j - 1;

      if (n[0] == 0) {
        if ('1' <= buffer[i] && buffer[i] <= '9') {
          n[0] = buffer[i];
        }

#ifdef PART2
        auto word_match =
            slice_matches_words(buffer.c_str(), buffer.c_str() + i);
        if (word_match.has_value()) {
          auto [offset, value] = word_match.value();
          n[0] = value;
          i += offset - 1;
        }
#endif
      }

      if (n[1] == 0) {
        if ('1' <= buffer[leni] && buffer[leni] <= '9') {
          n[1] = buffer[leni];
        }

#ifdef PART2
        auto word_match =
            slice_matches_words(buffer.c_str(), buffer.c_str() + leni);
        if (word_match.has_value()) {
          auto [offset, value] = word_match.value();
          n[1] = value;
          j += offset - 1;
        }
#endif
      }
    }

    if (std::strlen(n) == 2)
      total += (n[0] - '0') * 10 + n[1] - '0';
  } while (!buffer.empty());

  printf("%lu\n", total);

  return 0;
}
