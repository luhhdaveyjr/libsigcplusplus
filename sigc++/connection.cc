// -*- c++ -*-
/*
 * Copyright 2002, The libsigc++ Development Team
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#include <sigc++/connection.h>
using namespace std;

namespace sigc {

void connection::set_closure(functor::internal::closure_base* cl)
{
  if (closure_)
    closure_->remove_dependency(this);

  closure_ = cl;

  if (closure_)
    closure_->add_dependency(this, &notify);
}

void* connection::notify(void* d)
{
  connection* self = (connection*)d;
  self->closure_ = 0;
  return 0;
}

} /* namespace sigc */