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

#ifndef OBSERVABLE_HH
#define OBSERVABLE_HH

#include <boost/shared_ptr.hpp>

#include <rxcpp/observer.hh>

namespace RxCpp
{
  template<typename T>
  class IObservable
  {
  public:
    typedef boost::shared_ptr<IObservable<T> > Ptr;

  public:
    virtual void subscribe(typename IObserver<T>::Ptr observer)=0;

    virtual ~IObservable() {}
  };

  template<typename T>
  class IComposable
  {
  public:
    typedef boost::shared_ptr<IComposable<T> > Ptr;

  public:
    virtual void connect(typename IObservable<T>::Ptr observable)=0;

    virtual ~IComposable() {}
  };

  template<typename T>
  class IComposableObserver : public IObserver<T>, public IComposable<T>
  {
  public:
    typedef boost::shared_ptr<IComposableObserver<T> > Ptr;
  };

}

#endif
