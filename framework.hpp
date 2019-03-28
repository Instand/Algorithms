#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <utils.hpp>

namespace cs {
    class Framework {
    public:
        template<typename Func>
        static void execute(Func func, const std::string& failedMessage) {
            if (!cs::Benchmark::run(func)) {
                cs::Console::writeLine("\n", failedMessage);
                cs::Console::writeLine("Failed running other tests, fix previous test to correct execution");

                std::exit(0);
            }
        }
    };
}

#endif // FRAMEWORK_HPP
