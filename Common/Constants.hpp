#pragma once

namespace Argo::Common {
const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;
const char* const DEFAULT_WINDOW_TITLE = "New Window";

// Lock the window updates to a target framerate.
// Use -1 to not limit the window updates
const float TARGET_FPS = 60.0;
}  // namespace Argo::Common
