#ifndef FORWARDLISTTESTS_HPP
#define FORWARDLISTTESTS_HPP

#include <algorithm>

#include <utils.hpp>
#include <structures/forwardlist.hpp>
#include <algorithms.hpp>

namespace cs {
    class ForwardListTests {
    public:
        static bool testPushFront() {
            cs::Console::writeLine("Push front test started");

            cs::ForwardList<size_t> forwardList;

            for (size_t i = 0; i < 100; ++i) {
                forwardList.pushFront(i);
            }

            cs::Console::print("Forward list elements after push front ", forwardList);
            cs::Console::size(forwardList);

            auto index = forwardList.size() - 1;

            for (const auto& element : forwardList) {
                if (index != element) {
                    return false;
                }

                --index;
            }

            return true;
        }

        static bool testPopFront() {
            cs::Console::writeLine("Pop front test started");

            cs::ForwardList<size_t> list;

            for (size_t i = 0; i < 100; ++i) {
                list.pushFront(i);
            }

            for (size_t i = 0; i < 100; ++i) {
                list.popFront();
            }

            return list.isEmpty();
        }
    };
}

#endif // FORWARDLISTTESTS_HPP
