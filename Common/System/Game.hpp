#pragma once

namespace Argo::System {

/**
 * \brief `Game` is an abstraction around the various Game types. Current only `BaseGame` and `GLGame` are supported.
 */

template <typename T> class Game : public T {};
}  // namespace Argo::System
