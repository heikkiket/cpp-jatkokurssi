#include <chrono>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Manageri.cpp"

template<class T>
class Log_Ptr
{
public:
  //! Default constructor
  Log_Ptr(T *p)
  {
    luoLokitiedosto();
    _manageri = new Manageri();
    _p = p;

    logfile << timestamp() << "omistajuus siirretty: " << p << "\n\n";
  };

  //! Copy constructor
  Log_Ptr(const Log_Ptr<T> &other) {

    luoLokitiedosto();
    _manageri = other._manageri;
    _p = other._p;
    _manageri->lisaaViittaus();

    logfile << timestamp() << "Luotu kopio, joka osoittaa muistialueeseen " <<  _p << "\n\n";
  }

  //! Destructor
  virtual ~Log_Ptr() noexcept
  {
    vahennaViittauksia();
    logfile.close();
  };

  T* operator->()
  {
    logfile << timestamp() << "operator->" << _p << "\n\n";
    return _p;
  }

  T& operator*() {
    logfile << timestamp() << "operator*" << _p
            << "\n\n";
    return *_p;
  }

  //! Copy assignment operator
  Log_Ptr& operator=(const Log_Ptr &other) {

    if(this == &other) {
      return *this;
    }

    logfile << "Muistialueen " << _p << " paikalle kopioitu toinen muistialue "
            << other._p << ".\n\n";

    vahennaViittauksia();

    _p = other._p;
    _manageri = other._manageri;
    _manageri->lisaaViittaus();

    return *this;
  };


protected:
private:
  std::ofstream logfile;

  Manageri* _manageri;
  T *_p;

  void luoLokitiedosto()
  {
    std::string filename{"ptr.log" + std::to_string(rand())};
    logfile.open(filename);
  }

  void vahennaViittauksia() {
    _manageri->vahennaViittaus();
    logfile << timestamp() << "viittaus poistettu. Viittauksia: "
            << _manageri->viittaukset() << "\n\n";

    if (_manageri->viittaukset() == 0) {
      logfile << timestamp() << "Muistialue " << _p << " ja sen manageri tuhottu.\n\n";
      delete _p;
      delete _manageri;
    }
  }

  std::string timestamp(){
    const auto p1 = std::chrono::system_clock::now();
    std::time_t today_time = std::chrono::system_clock::to_time_t(p1);
    return std::string { std::ctime(&today_time) };
  }

};
