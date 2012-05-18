/*
 * RxCpp - C# Reactive Extensions for C++
 * Copyright (C) 2012 Kees-Jan Dijkzeul
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License, version 2, as published by the Free Software Foundation.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef TARGETS_HH
#define TARGETS_HH

#include <boost/function.hpp>

#include <rxcpp/observer.hh>
#include <rxcpp/shared_from_this.hh>

namespace RxCpp
{
  namespace Detail
  {
    template<typename T>
    class Target : public IComposableObserver<T>, public virtual RxCpp::SharedFromThis::Base
    {
    private:
      boost::function<void(const T&)> onNextFunc;
      boost::function<void(void)> onCompletedFunc;
      boost::function<void(std::exception& e)> onErrorFunc;
      typename IObservable<T>::Ptr observable;

    public:
      Target(boost::function<void(const T&)> onNextFunc,
             boost::function<void(void)> onCompletedFunc,
             boost::function<void(std::exception& e)> onErrorFunc)
        : onNextFunc(onNextFunc), onCompletedFunc(onCompletedFunc), onErrorFunc(onErrorFunc)
      {}

      static typename IComposableObserver<T>::Ptr create(boost::function<void(const T&)> onNextFunc,
                                                         boost::function<void(void)> onCompletedFunc,
                                                         boost::function<void(std::exception& e)> onErrorFunc)
      { return typename IComposableObserver<T>::Ptr(new Target(onNextFunc, onCompletedFunc, onErrorFunc)); }
      
    
      // IObserver ///////////////////////////////////////////////////////////
      virtual void onNext(const T& value) { onNextFunc(value); }
      virtual void onCompleted() { onCompletedFunc(); }
      virtual void onError(std::exception& e) { onErrorFunc(e); }
    
      // IComposable /////////////////////////////////////////////////////////
      virtual void connect(typename IObservable<T>::Ptr observable)
      {
        this->observable = observable;
        observable->subscribe(shared_from_this<IObserver<T> >());
      }
    };
  }
  
  namespace
  {
    void dummyOnCompleted() {}
    void dummyOnError(std::exception&) {}
  }
    
  template<typename T>
  typename IComposableObserver<T>::Ptr onNext(boost::function<void(T)> onNextFunc)
  {
    return Detail::Target<T>::create(onNextFunc, dummyOnCompleted, dummyOnError);
  }
}


#endif
