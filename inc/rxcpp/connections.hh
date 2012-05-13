/*
 * rxcpp - c# reactive extensions for c++
 * copyright (c) 2012 kees-jan dijkzeul
 * 
 * this library is free software; you can redistribute it and/or
 * modify it under the terms of the gnu lesser general public
 * license, version 2, as published by the free software foundation.
 * 
 * this library is distributed in the hope that it will be useful,
 * but without any warranty; without even the implied warranty of
 * merchantability or fitness for a particular purpose.  see the gnu
 * lesser general public license for more details.
 * 
 * you should have received a copy of the gnu lesser general public
 * license along with this library; if not, write to the free software
 * foundation, inc., 51 franklin street, fifth floor, boston, ma  02110-1301  usa
 */

#ifndef CONNECTIONS_HH
#define CONNECTIONS_HH

#include <rxcpp/observable.hh>

namespace RxCpp
{
  template<typename T>
  boost::shared_ptr<IObserver<T> > operator>>(boost::shared_ptr<IObservable<T> > source, boost::shared_ptr<IObserver<T> > target)
  {
    ((void)source);
    return target;
  }
}

#endif
