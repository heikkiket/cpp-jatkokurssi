#include <iostream>
#include "Log_Ptr.cpp"
#include "Henkilo.cpp"

int main(int argc, char *argv[])
{
  Log_Ptr<Henkilo> h{new Henkilo{"Matti"}};

  Log_Ptr<Henkilo> j { h };

  h->tervehdi();
  (*h).tervehdi();

  // j->tervehdi();

  return 0;
}
