#include <chrono>
#include <cstdlib>
#include <fstream>
#include <string>

template<class T>
class Log_Ptr
{
public:
  //! Default constructor
  Log_Ptr(T *p)
  {
    _p = p;
    std::string filename{"ptr.log" + std::to_string(rand())};
    logfile.open(filename);
    logfile << timestamp() << "omistajuus siirretty: " << _p << "\n\n";
  };

  //! Copy constructor
  Log_Ptr(const Log_Ptr &other) {
    logfile << "Yritettiin kopioida " << &other << " mutta edelleen osoittaa "
            << _p << "\n";
  }

  //! Destructor
  virtual ~Log_Ptr() noexcept
  {
    logfile << timestamp() << "olio tuhottu: " << _p << "\n\n";
    logfile.close();
  };

  T* operator->()
  {
    logfile << timestamp() << "operator->" << _p << "\n\n";
    return _p;
  }

  T& operator*()
  {
    logfile << timestamp() << "operator*" << _p << "\n\n";
    return *_p;
  }

  //! Copy assignment operator
  Log_Ptr& operator=(const Log_Ptr &other) {};

  //! Move assignment operator
  Log_Ptr& operator=(Log_Ptr &&other) noexcept {};



protected:
private:
  std::ofstream logfile;

  std::string timestamp(){
    const auto p1 = std::chrono::system_clock::now();
    std::time_t today_time = std::chrono::system_clock::to_time_t(p1);
    return std::string { std::ctime(&today_time) };
  }


  T *_p;
};
