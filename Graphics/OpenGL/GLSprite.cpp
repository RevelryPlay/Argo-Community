#include "GLSprite.hpp"

namespace Argo::Graphics {
std::vector< Types::Vertex > GLSprite::calculateRecVertices( float viewPortHeight, float viewPortWidth ) {

    // Normalize width and height to [-1.0, 1.0] range
    float norm_width = ( width / viewPortWidth );
    float norm_height = ( height / viewPortHeight );

    std::vector< Types::Vertex > vertices( 4 );

    // Triangle 1
    // Vertex 0 - bottom left
    vertices[ 0 ].x = -norm_width;
    vertices[ 0 ].y = -norm_height;
    vertices[ 0 ].z = 0.0f;

    // Vertex 1 - top left
    vertices[ 1 ].x = norm_width;
    vertices[ 1 ].y = -norm_height;
    vertices[ 1 ].z = 0.0f;

    // Vertex 2 - bottom right
    vertices[ 2 ].x = norm_width;
    vertices[ 2 ].y = norm_height;
    vertices[ 2 ].z = 0.0f;

    // Triangle 2
    // Vertex 3 - top right
    vertices[ 3 ].x = -norm_width;
    vertices[ 3 ].y = norm_height;
    vertices[ 3 ].z = 0.0f;
//
//        // Vertex 4 - bottom right
//        vertices[4].x = norm_width;
//        vertices[4].y = -norm_height;
//        vertices[4].z = 0.0f;
//
//        // Vertex 5 - top left
//        vertices[5].x = -norm_width;
//        vertices[5].y = norm_height;
//        vertices[5].z = 0.0f;

    return vertices;
}

}  // namespace Argo::Graphics
