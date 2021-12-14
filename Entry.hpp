#ifndef HEADER_ENTRY
#define HEADER_ENTRY
#include <string>
using namespace std;

class Entry
{
public:
  string source;
  float amount;

  Entry(string s, float n) : source(s), amount(n) {}
};
#endif