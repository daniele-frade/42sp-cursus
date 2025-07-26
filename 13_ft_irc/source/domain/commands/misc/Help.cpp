#include "commands/misc/Help.hpp"
#include "ClientService.hpp"
#include "Client.hpp"
#include "Macros.hpp"


Help::Help(Server* server) : ACommand(server, false) {}
Help::~Help() {}


// syntax: HELP
void Help::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    std::string help;

    help += "HELP: Exibe informações sobre os comandos disponíveis\n";
    help += "INFO: Exibe informações sobre o servidor\n";
    help += "LIST: Lista os canais no servidor\n";
    help += "NAMES #<channel>: Mostra os membros de um canal\n";
    help += "NOTICE <nickname> :<message>: Envia uma mensagem de notificação para um usuário\n";
    help += "NOTICE #<channel> :<message>: Envia uma mensagem de notificação para um canal\n";
    help += "PING <server_addr>: Envia um PING para o servidor para verificar a conexão\n";
    help += "PONG <server_addr>: Responde a um PING enviado pelo servidor\n";
    help += "INVITE <nickname> #<channel>: Convida um usuário para um canal\n";
    help += "KICK #<channel> <client> :<message>: Expulsa um usuário de um canal com uma mensagem de motivo\n";
    help += "MODE #<channel> <flag> <args>: Altera o modo de um canal (ex: privacidade, acesso, etc)\n";
    help += "TOPIC #<channel> :<new_topic>: Altera o tópico de um canal\n";
    help += "TOPIC #<channel>: Mostra o tópico de um canal\n";
    help += "NICK <nickname>: Altera o seu nickname\n";
    help += "PASS <password>: Define a senha para o seu login (antes de NICK/USER)\n";
    help += "QUIT :<message>: Encerra a sua sessão no servidor com uma mensagem\n";
    help += "USER <username> <hostname> <servername> :<realname>: Define o seu usuário e detalhes do servidor\n";
    help += "JOIN #<channel> <key>: Entra em um canal com uma chave (senha)\n";
    help += "JOIN <channel>: Entra em um canal\n";
    help += "PART #<channel> :<message>: Sai de um canal com uma mensagem de saída\n";
    help += "PRIVMSG <nickname> :<message>: Envia uma mensagem privada para um usuário\n";
    help += "PRIVMSG #<channel> :<message>: Envia uma mensagem para um canal\n";

    ClientService::send_message(client, help.c_str());
}

bool Help::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "HELP::Validate parameters..." << std::endl;
    if (args.empty())
        return true;
    ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("HELP")));
    return false;
}
