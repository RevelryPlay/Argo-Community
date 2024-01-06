#pragma once

namespace Argo::Types {
struct BaseEntity {

    BaseEntity() = default;
    virtual ~BaseEntity() = default;

    float xPos{ 0 };
    float yPos{ 0 };
    float width{ 0 };
    float height{ 0 };
    float rotation{ 0 };
    float scale{ 1.0F };
};
}  // namespace Argo::Types
