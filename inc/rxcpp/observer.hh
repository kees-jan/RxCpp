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

#ifndef OBSERVER_HH
#define OBSERVER_HH

#include <boost/shared_ptr.hpp>

namespace RxCpp
{
  template<typename T>
  class IObserver
  {
  public:
    typedef boost::shared_ptr<IObserver<T> > Ptr;

  public:
    virtual void onNext(const T& value)=0;
    virtual void onCompleted()=0;
    virtual void onError(std::exception& e)=0;

    virtual ~IObserver() {}
  };
}
#endif
