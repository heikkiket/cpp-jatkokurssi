#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void spell(int &hp)
{
  hp = hp - 100;
  if(hp < 0)
    hp = 0;
}

void printVihut(vector<int> vihut)
{
  for(auto vihu : vihut) {
    cout << "Vihollisen HP: " << vihu << "\n";
  }
}

class VihuTaikoja
{
public:
  VihuTaikoja(int vaikutus) : _vaikutus(vaikutus) {}
  void operator()(int &hp)
  {
    hp = hp - _vaikutus;
    if (hp < 0)
      hp = 0;
  }
private:
  int _vaikutus;

};

int main(int argc, char *argv[])
{
  auto viholliset = vector<int>(5, 550);

  cout << "Ennen taikoja viholliset: \n";
  printVihut(viholliset);


  std::for_each(viholliset.begin(), viholliset.end(), spell);

  cout << "ekan taikakierroksen jälkeen viholliset: \n";
  printVihut(viholliset);

  auto loitsija = VihuTaikoja(100);
  for_each(viholliset.begin(), viholliset.end(), loitsija);
  cout << "tokan taikakierroksen jälkeen viholliset: \n";
  printVihut(viholliset);

  for_each(viholliset.begin(), viholliset.end(), [](int &hp) {
    hp = hp - 100;
    if (hp < 0)
      hp = 0;
  });

  cout << "kolmannen taikakierroksen jälkeen viholliset: \n";
  printVihut(viholliset);

  auto loitsija2 = [](int &hp) {
    hp = hp - 100;
    if (hp < 0)
      hp = 0;
  };

  for_each(viholliset.begin(), viholliset.end(), loitsija2);

  cout << "neljännen taikakierroksen jälkeen viholliset: \n";
  printVihut(viholliset);
  return 0;
}
