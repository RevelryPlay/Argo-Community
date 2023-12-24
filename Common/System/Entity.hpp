#pragma once

namespace Argo::System {

/**
 * \brief `Entity` is an abstraction around the various Entity types.
 */

template< typename T > struct Entity : T {};
}  // namespace Argo::System
