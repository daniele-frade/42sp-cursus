
LOGIN=dfrade
MARIA_DIR=/home/$(LOGIN)/data/mariadb
WORDPRESS_DIR=/home/$(LOGIN)/data/wordpress

DOCKER_COMPOSE_COMMAND=docker-compose -f ./srcs/docker-compose.yaml

all: config build up

config:
	@if ! grep -q '$(LOGIN)' /etc/hosts; then \
		echo "127.0.0.1 $(LOGIN).42.fr" | sudo tee -a /etc/hosts > /dev/null; \
	fi
	
	@if [ ! -d "$(WORDPRESS_DIR)" ]; then \
		sudo mkdir -p $(WORDPRESS_DIR); \
	fi

	@if [ ! -d "$(MARIA_DIR)" ]; then \
		sudo mkdir -p $(MARIA_DIR); \
	fi

build:
	$(DOCKER_COMPOSE_COMMAND) build

up:
	$(DOCKER_COMPOSE_COMMAND) up -d

down:
	$(DOCKER_COMPOSE_COMMAND) down

ps:
	$(DOCKER_COMPOSE_COMMAND) ps

ls:
	docker volume ls

clean:
	$(DOCKER_COMPOSE_COMMAND) down --rmi all --volumes

fclean: clean
	docker system prune --force --all --volumes
	sudo rm -rf /home/$(LOGIN)

re: fclean all

.PHONY: all up config build down ls clean fclean
