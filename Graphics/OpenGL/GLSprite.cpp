#include "GLSprite.hpp"

namespace Argo::Graphics {
std::vector< Types::Vec3 > GLSprite::calculateRecVertices( const float viewPortWidth,
    const float viewPortHeight ) const {

    // Normalize width and height to [-1.0, 1.0] range
    const float norm_width = ( width / viewPortWidth );
    const float norm_height = ( height / viewPortHeight );

    std::vector< Types::Vec3 > vertices( 4 );

    // Triangle 1
    // Vertex 0 - bottom left
    vertices[ 0 ].x = -norm_width;
    vertices[ 0 ].y = -norm_height;
    vertices[ 0 ].z = 0.0F;

    // Vertex 1 - top left
    vertices[ 1 ].x = norm_width;
    vertices[ 1 ].y = -norm_height;
    vertices[ 1 ].z = 0.0F;

    // Vertex 2 - bottom right
    vertices[ 2 ].x = norm_width;
    vertices[ 2 ].y = norm_height;
    vertices[ 2 ].z = 0.0F;

    // Triangle 2
    // Vertex 3 - top right
    vertices[ 3 ].x = -norm_width;
    vertices[ 3 ].y = norm_height;
    vertices[ 3 ].z = 0.0F;

    // // Vertex 4 - bottom right
    // vertices[4].x = norm_width;
    // vertices[4].y = -norm_height;
    // vertices[4].z = 0.0F;

    // // Vertex 5 - top left
    // vertices[5].x = -norm_width;
    // vertices[5].y = norm_height;
    // vertices[5].z = 0.0F;

    return vertices;
}


}  // namespace Argo::Graphics
