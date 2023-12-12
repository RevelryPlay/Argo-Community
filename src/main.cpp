#include "Runner.hpp"

using namespace Argo::System;

int main( int /*unused*/, char ** /*unused*/ ) {
    Argo::Runner runner = *new Argo::Runner();
    runner.run();
}
