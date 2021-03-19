#include <iostream>

class Henkilo
{
public:
  Henkilo(std::string nimi) {_nimi = nimi; }
  void tervehdi() { std::cout << "Tervehdys. Minun nimeni on "<< _nimi << ".\n"; }
  virtual ~Henkilo() {};
private:
  std::string _nimi;
};
