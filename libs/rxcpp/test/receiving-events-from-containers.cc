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

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <list>
#include <typeinfo>
#include <iostream>

#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>
#include <boost/function.hpp>

#include <rxcpp.hh>

using namespace RxCpp;

//////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(Receiving_Events_From_Containers)

BOOST_AUTO_TEST_CASE(with_lambdas)
{
  std::list<int> values = {1, 2, 3, 4, 5};
  int sum = 0;

  source(values) >> target<int>([&sum](int x){sum+=x;});

  BOOST_CHECK_EQUAL(15, sum);
}

BOOST_AUTO_TEST_SUITE_END()
