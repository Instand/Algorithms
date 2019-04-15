#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <benchmark.hpp>

namespace cs {
    class Framework {
    public:
        template<typename Func>
        static void execute(Func func, const std::string& failedMessage) {
            try {
                if (!cs::Benchmark::run(func)) {
                    cs::Console::writeLine("\n", failedMessage);
                    cs::Console::writeLine("Failed running other tests, fix previous test to correct execution");

                    std::exit(0);
                }
            }
            catch (const std::exception& e) {
                cs::Console::writeLine("Exception catched, message: ", e.what());
                cs::Console::writeLine("Benchmark would be terminated");

                std::terminate();
            }
        }
    };
}

#endif // FRAMEWORK_HPP
