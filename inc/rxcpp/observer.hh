#ifndef OBSERVER_HH
#define OBSERVER_HH

namespace RxCpp
{
  template<typename T>
  class IObserver
  {
    virtual void onNext(const T& value)=0;
    virtual void onCompleted()=0;
    virtual void onError(std::exception& e)=0;

    virtual ~IObserver() {}
  };
}
#endif
