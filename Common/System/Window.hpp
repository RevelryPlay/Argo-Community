#pragma once

namespace Argo::System {

/**
 * \brief `Window` is an abstraction around the various window types.
 * Currently only `BaseWindow` and `GLWindow` are supported.
 */

template< typename T > class Window : public T {};

}  // namespace Argo::System
