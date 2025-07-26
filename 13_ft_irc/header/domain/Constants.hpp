#pragma once

#ifndef CONSTANTS_HPP
# define CONSTANTS_HPP

#include <string>

const int MIN_PORT = 1024;
const int MAX_PORT = 65535;

const int MAX_BLACKLIST_VIOLATIONS = 3;

const int MAX_CONNECTIONS = 20;

const int MAX_EVENTS = 20;
const int BUFFER_SIZE = 100;

const std::string IP_ADDRESS = "127.0.0.1";

const std::string LISTEN_ADDRESS = "0.0.0.0";

#endif
