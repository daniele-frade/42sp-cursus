#pragma once

#ifndef SIGNALMANAGER_HPP
# define SIGNALMANAGER_HPP

# include <csignal>
# include <cstring>
# include <stdexcept>

class SignalManager {
    private:
        static bool*   _running;

        static void    _signal_handler(int signum);

    public:
        static void    initialize(bool* running);
};

#endif