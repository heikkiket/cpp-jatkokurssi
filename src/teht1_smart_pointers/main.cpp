#include <iostream>
#include "Log_Ptr.cpp"
#include "Henkilo.cpp"

int main(int argc, char *argv[])
{
  Log_Ptr<Henkilo> h{new Henkilo{"Matti"}};

  Log_Ptr<Henkilo> j { h };

  h->tervehdi();
  (*h).tervehdi();

  j->tervehdi();

  h = h; //Itseviittaus onnistuu

  Log_Ptr<Henkilo> h2 {new Henkilo{"Heikki"}};
  h2->tervehdi();
  h2= h;

  h2->tervehdi();

  return 0;
}
