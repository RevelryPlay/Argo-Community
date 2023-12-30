#pragma once

namespace Argo::Types {
struct BaseScene {
    BaseScene() = default;
    BaseScene( const int width, const int height );

    // GUID

    // list<GUID> entityIds = [];
    // list<GUID> lightIds = [];

    void SetWidth( const int width );
    [[nodiscard]] int GetWidth() const;

    void SetHeight( const int height );
    [[nodiscard]] int GetHeight() const;

  private:
    int width_{ 0 };
    int height_{ 0 };
};
}  // namespace Argo::Types
