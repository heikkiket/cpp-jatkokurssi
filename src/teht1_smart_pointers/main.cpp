#include <iostream>
#include "Log_Ptr.cpp"

int main(int argc, char *argv[])
{
  Log_Ptr<int> p{new int{5}};

  Log_Ptr<int> j { p };


  return 0;
}
