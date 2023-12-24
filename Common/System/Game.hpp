#pragma once

namespace Argo::System {

/**
 * \brief `Game` is an abstraction around the various Game types.
 */

template< typename T > struct  Game : T {};
}  // namespace Argo::System
