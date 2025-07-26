# 42 Cursus - ft_irc

<img src="./assets/ft_irce.png" alt="completion-without-bonus-badge" align="left">

Este projeto é uma implementação de servidor IRC em C++ 98, utilizando a RFC 1459. O objetivo é criar um servidor leve, orientado a eventos, capaz de lidar com múltiplos clientes, suportar os recursos do protocolo IRC e gerenciar a comunicação em tempo real entre canais. Os projeto é compatível com os clients WeeChat e HexChat (este segundo sem todas as funcionalidades). O foco está no uso de multiplexadores para o gerenciamento não-bloqueante dos sockets.

## Features <img src="https://img.shields.io/badge/GRADE-100%2F100-green" align="right">

- Compatível com **IRC protocol (RFC 1459)**.
- Lida com múltiplos clients através de **multiplexing** (epoll).
- Criação e gerenciamento de canais.
- Gerenciamento de nickname do client e status do usuário.
- Arquitetura orientada a eventos para escalabilidade.
- Suporte a comandos básicos do IRC, como:
    - [x] `PASS <password>`: Entra com a senha do Server
    - [x] `NICK <nickname>`: Define seu nickname de usuário
    - [x] `USER <username> <hostname> <servername> :<realname>`: Define seu nome de usuário e seu nome real
    - [x] `JOIN <channel> <key>`: Entra em um canal
    - [x] `PART <channels> :<message>`: Sai de um canal
    - [x] `PRIVMSG <msgtarget> :<message>`: Envia uma mensagem particular a um usuário
    - [x] `QUIT :<message>`: Desconecta-se do servidor
    - [x] `TOPIC <channel>` ou `TOPIC <channel> :<new_topic>`: Lê ou redefine o tópico de um canal
    - [x] `INVITE <nickname> <channel>`: Envia um invite para um canal a um usuário
    - [x] `KICK <channel> <client> :<message>`: Expulsa um usuário de um canal
    - [x] `MODE <nickname> <flags>` ou `MODE <channel> <flags> <args>`: Altera modos de um usuário ou canal

        | Modos | Descrição |
        |:---:|:--- |
        | i | Definir/remover o canal somente para convidados (Invite-only). |
        | t | Definir/remover as restrições do comando TOPIC para operadores de canal. |
        | k | Definir/remover a chave (senha) do canal. |
        | o | Dar/tirar privilégios de operador de canal. |
        | l | Definir/remover o limite de usuários do canal. |


### Comando para testar componentes separados

- `(echo -n "NI"; sleep 1; echo -n "CK "; sleep 1; echo " rulyo") | nc 127.0.0.1 6667`

### Testers

- PASS 123456

- USER Ana * 0 Ana Maria
- NICK Mariazinha

- USER Bia * 0 Ana Beatriz
- NICK Biazinha

- `(echo "PASS 123456"; echo "USER Carol * 0 Ana Carolina"; echo "NICK Carolzinha") | nc 127.0.0.1 6667`

## Project Structure

- **source/\*\***: Diretório para arquivos cpp.
- **header/\*\***: Diretório para arquivos hpp.
- Utilizada Clean Arch para divisão do código em camadas Application, Domain e Infrastructure.
- Utilizado [Command Pattern](https://refactoring.guru/design-patterns/command) para os comandos.
