#pragma once

namespace Argo::Common {
constexpr int DEFAULT_WINDOW_WIDTH{ 1024 };
constexpr int DEFAULT_WINDOW_HEIGHT{ 1024 };
const char *const DEFAULT_WINDOW_TITLE{ "New Window" };

// Lock the window updates to a target framerate.
// Use -1 to not limit the window updates
constexpr short TARGET_FPS{ 60 };
}  // namespace Argo::Common
