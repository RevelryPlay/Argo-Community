#include "ArgoConfig.h"
#include "ColorConverter.hpp"
#include "Types/CommonColor.hpp"

#include "System/Game.hpp"

#include <iostream>

using namespace std;

int main(int /*unused*/, char ** /*unused*/)
{
  //  system("clear");

  // Get System Modules
  // Base Error Handlers
  // OS Specific Modules

// Linux Specific Code
#ifdef __linux__
  fprintf(stdout, "Running on Linux\r\n");

// Mac OS Specific Code
#elif defined(__APPLE__) && defined(__MACH__)
  fprintf(stdout, "Running on MacOS\r\n");

  // Windows Specific Code
#elifdef _WIN32
  fprintf(stdout, "Running on Windows\r\n");
#endif

  // File System Utilities
  // Loggers
  // Serializers
  // Asset Loaders
  // Save / Load
  // Settings Handler

  // Graphic Utilities
  // Audio Utilities
  // Input Utilities
  // Networking Utilities

  // Get Registered Extensions
  // Handle Preloads
  // Core Event Loop

  string const git_sha GIT_HASH;

  fprintf(stdout,
    "%s Version %d.%d.%d \r\n",
    PROJECT_NAME,
    PROJECT_VERSION_MAJOR,
    PROJECT_VERSION_MINOR,
    PROJECT_VERSION_PATCH);
  std::cout << "GIT HASH " << git_sha << "\r\n";
  fprintf(stdout, "%s \r\n", PROJECT_DESCRIPTION);
  fprintf(stdout, "%s \r\n", PROJECT_URL);

  const auto *const inColor = "6A468E80";
  Argo::CommonColor const color = Argo::Utilities::ConvertColor::FromHex(inColor);

  fprintf(stdout,
    "Color in %s, \r\n CommonColor red %f green %f blue %f alpha %f\r\n Back to hex for validation %s \r\n",
    inColor,
    color.red,
    color.green,
    color.blue,
    color.alpha,
    color.ToHex().c_str()
  );

  Argo::System::Game game = *new Argo::System::Game();

  if (!game.init()) {
    fprintf(stderr, "Failed to initialize the game. See the logs about for more details.");
    return -1;
  }

  game.run();

  return 0;
}
