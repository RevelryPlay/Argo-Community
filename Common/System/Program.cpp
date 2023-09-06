#include "Program.hpp"

namespace Argo::System {

Program::Program() = default;

Program::~Program() { cleanup(); }

bool Program::init() { return true; }
void Program::run() {}


void Program::cleanup() {}

}// namespace Argo::System
