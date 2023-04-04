#include <gtest/gtest.h>
#include <afsm/fsm.hpp>

#include <iostream>

// Events
struct start {};
struct stop {};

// State machine definition
struct minimal_def : ::afsm::def::state_machine<minimal_def> {
    //@{
    /** @name States */
    struct initial      : state<initial> {};
    struct running      : state<running> {};
    struct terminated   : terminal_state<terminated> {};
    //@}

    using initial_state = initial;
    using transitions   = transition_table<
    /*  State       Event       Next        */
    tr< initial,    start,      running     >,
    tr< running,    stop,       terminated  >
    >;
};

// State machine object
using minimal = ::afsm::state_machine<minimal_def>;

minimal fsm;
TEST(My, SimpleTest)
{
    fsm.process_event(start{});
    fsm.process_event(stop{});
}
