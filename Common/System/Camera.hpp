#pragma once

namespace Argo::System {

/**
 * \brief `Camera` is an abstraction around the various Camera types.
 */

template< typename T > struct Camera : T {};
}  // namespace Argo::System
