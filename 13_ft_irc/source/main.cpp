#include "Vault.hpp"
#include "Socket.hpp"
#include "Multiplexer.hpp"
#include "Server.hpp"
#include "Utils.hpp"

int main(int ac, char** av) {
    try {
        int         port        = Utils::set_port(ac, av);
        std::string password    = av[2];

        IVault*         vault           = new Vault(password);
        ISocket*        server_socket   = new Socket(LISTEN_ADDRESS, port);
        IMultiplexer*   multiplexer     = new Multiplexer(server_socket->get_fd());

        Server      server(vault, server_socket, multiplexer);

        server.start();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}


/* TESTANDO CONNECTIVIDADE
nc -zv 0.0.0.1 6667
Se o servidor estiver ativo e aceitando conexões, aparece "Ncat: Connected to 127.0.0.1:6667".
Caso contrário, verá uma mensagem de erro, "Ncat: Connection refused."

ou

netstat -tuln | grep 6667
Se o servidor estiver rodando, o comando retornará uma linha mostrando que ele está escutando na porta 6667.
Se não houver saída, o servidor não está rodando ou não está escutando na porta especificada.
*/


/* CONECTANDO AO SERVIDOR
nc 0.0.0.0 6667
Para desconectar, necessário o uso do ctrl+C.
*/