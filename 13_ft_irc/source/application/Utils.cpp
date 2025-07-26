# include "Utils.hpp"
# include "Constants.hpp"

std::string Utils::get_time() {
    time_t rawtime;
    struct tm *timeinfo;
    char time_string[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(time_string, sizeof(time_string), "%d-%m-%Y %H:%M:%S", timeinfo);

    return std::string(time_string);
}

int Utils::get_port(const char* input) {
    std::istringstream iss(input);
    int value;
    char leftover;

    if (!(iss >> value) || (iss >> leftover))
        throw std::invalid_argument(std::string("Invalid port: '") + input + "'");

    if (value < MIN_PORT || value > MAX_PORT) {
        std::ostringstream msg;
        msg << "Port must be between " << MIN_PORT << " and " << MAX_PORT;
        throw std::invalid_argument(msg.str());
    }

    return value;
}

void Utils::validate_args(int argc, const char* program_name) {
    if (argc != 3) {
        std::ostringstream msg;
        msg << "Usage: " << program_name << " <port> <password>";
        throw std::invalid_argument(msg.str());
    }
}

int Utils::set_port(int argc, char** argv) {
    validate_args(argc, argv[0]);
    return get_port(argv[1]);
}
