#ifndef OBSERVABLE_HH
#define OBSERVABLE_HH

#include <rxcpp/observer.hh>

namespace RxCpp
{
  template<typename T>
  class IObservable
  {
    void subscribe(IObserver<T> observer)=0;
  };
}

#endif
