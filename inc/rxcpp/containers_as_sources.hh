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

#ifndef CONTAINERS_AS_SOURCES_HH
#define CONTAINERS_AS_SOURCES_HH

#include <boost/foreach.hpp>

#include <rxcpp/observable.hh>

namespace RxCpp
{
  namespace Detail
  {
    template<typename ContainerType>
    class ContainerAsSource : public IObservable<typename ContainerType::value_type>
    {
    private:
      ContainerType& container;
      
    public:
      ContainerAsSource(ContainerType& container)
        :container(container)
      {}

      static typename IObservable<typename ContainerType::value_type>::Ptr create(ContainerType& container)
      { return typename IObservable<typename ContainerType::value_type>::Ptr(new ContainerAsSource(container)); }

      // IObservable /////////////////////////////////////////////////////////
      virtual void subscribe(typename IObserver<typename ContainerType::value_type>::Ptr observer)
      {
        BOOST_FOREACH(typename ContainerType::value_type element, container)
          observer->onNext(element);
        observer->onCompleted();
      }
    };
  }
  

  template<typename ContainerType>
  typename IObservable<typename ContainerType::value_type>::Ptr source(ContainerType container)
  {
    return Detail::ContainerAsSource<ContainerType>::create(container);
  }
}


#endif
