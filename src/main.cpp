#include "ArgoConfig.h"
#include <iostream>
#include "Types/CommonColor.hpp"
#include "ColorConverter.hpp"

int main(int, char **) {
  // Get System Modules
  // Base Error Handlers
  // OS Specific Modules
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


    fprintf(stdout, "%s Version %d.%d.%d \r\n",
            PROJECT_NAME,
            PROJECT_VERSION_MAJOR,
            PROJECT_VERSION_MINOR,
            PROJECT_VERSION_PATCH);
    fprintf(stdout, "%s \r\n", PROJECT_DESCRIPTION);
    fprintf(stdout, "%s \r\n", PROJECT_URL);

    unsigned int inColor = 0x207350ff;
    Argo::CommonColor color = Argo::Utilities::ConvertColor::FromHex(&inColor);
    fprintf(
      stdout,
      "Color in 0x207350ff, CommonColor red %f green %f blue %f alpha %f\r\n",
      color.red,
      color.green,
      color.blue,
      color.alpha
      );

    return 0;
}
