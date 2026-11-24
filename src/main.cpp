// main.cpp — entry point. Wires config and subsystems together.

#include "lagfixsuite/settings.h"
#include "lagfixsuite/routes.h"
#include "lagfixsuite/tweaks.h"
#include "lagfixsuite/monitor.h"
#include "lagfixsuite/cli.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    lagfixsuite::Settings settings = lagfixsuite::Settings::load_default();
    lagfixsuite::Routes routes(settings.store_path);
    lagfixsuite::Tweaks tweaks(settings.store_path);
    lagfixsuite::Monitor monitor(settings.store_path);
    lagfixsuite::Cli cli(settings.store_path);
    std::fprintf(stderr, "[lag-fix-suite] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
