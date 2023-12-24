#pragma once

namespace Argo::System {

/**
 * \brief `Scene` is an abstraction around the various Scene types.
 */

template< typename T > struct Scene : T {};
}  // namespace Argo::System
