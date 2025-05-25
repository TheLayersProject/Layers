/*
 * Copyright (C) 2025 The Layers Project
 *
 * This file is part of Layers.
 *
 * Layers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Layers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Layers. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef LCONNECTOR_H
#define LCONNECTOR_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lconnections.h"

LAYERS_NAMESPACE_BEGIN
template <typename... Args>
class LAYERS_EXPORT LConnector
{
public:
  using Callback = std::function<void(Args...)>;

private:
  template<typename... T>
  class Impl {
  public:
    LConnectionID next_connection_id{ 0 };
    std::map<LConnectionID, std::function<void(T...)>> connections;
  };
  
  Impl<Args...>* pimpl;

public:
  LConnector() : pimpl(new Impl<Args...>()) {}
  ~LConnector() { delete pimpl; }

  LConnectionID connect(Callback callback)
  {
    pimpl->connections[pimpl->next_connection_id] = callback;
    return pimpl->next_connection_id++;
  }

  void disconnect(const LConnectionID& connection)
  {
    pimpl->connections.erase(connection);
  }

  void disconnect_all()
  {
    pimpl->connections.clear();
  }

  void execute(Args... args)
  {
    for (auto& [id, callback] : pimpl->connections)
    {
      callback(args...);
    }
  }
};

LAYERS_NAMESPACE_END

#endif // LCONNECTOR_H
