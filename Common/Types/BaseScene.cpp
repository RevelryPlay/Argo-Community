#include "BaseScene.hpp"

namespace Argo::Types {

/**
 * \brief Construct a new BaseScene object
 * \param width
 * \param height
 */
BaseScene::BaseScene( const int width, const int height ) : width_( width ), height_( height ) {}

int BaseScene::GetWidth() const { return width_; }
void BaseScene::SetWidth( const int width ) { width_ = width; }

int BaseScene::GetHeight() const { return height_; }
void BaseScene::SetHeight( const int height ) { height_ = height; }

}  // namespace Argo::Types
