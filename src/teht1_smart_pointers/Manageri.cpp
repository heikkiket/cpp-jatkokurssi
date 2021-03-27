class Manageri
{
public:
  Manageri() {
    _viittaukset++;
  };

  virtual ~Manageri() {}

  void vahennaViittaus() {_viittaukset--;}
  void lisaaViittaus() {_viittaukset++;}
  int viittaukset() { return _viittaukset;}

private:
  int _viittaukset{0};
};
