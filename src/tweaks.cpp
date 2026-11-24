// tweaks.cpp — part of lag-fix-suite.

#include "lagfixsuite/tweaks.h"

#include <cstdio>

namespace lagfixsuite {

Tweaks::Tweaks(const std::string& config_path)
    : config_path_(config_path) {}

void Tweaks::configure(const std::string& key, const std::string& value) {
    if (key == "verbose") verbose_ = (value == "true");
}

bool Tweaks::run() {
    if (verbose_) std::fprintf(stderr, "[lag-fix-suite] tweaks: run\n");
    // core logic lives here
    return true;
}

}  // namespace lagfixsuite
