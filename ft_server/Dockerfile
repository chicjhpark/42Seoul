FROM	debian:buster

RUN	apt-get update
RUN	apt-get -y install \
	nginx \
	openssl \
	mariadb-server \
	php-mysql \
	php7.3-fpm
RUN	mkdir ./var/www/html/wordpress
RUN	mkdir ./var/www/html/phpmyadmin

COPY	./srcs/default ./etc/nginx/sites-available/
COPY	./srcs/wordpress ./var/www/html/wordpress/
COPY	./srcs/phpmyadmin ./var/www/html/phpmyadmin/
COPY	./srcs/localhost.crt ./etc/ssl/certs/
COPY	./srcs/localhost.key ./etc/ssl/private/

EXPOSE	80 443

RUN	service mysql start
RUN	echo "mysql"
RUN	echo "CREATE DATABASE wordpress;"
RUN	echo "CREATE USER 'jaehpark'@'localhost' IDENTIFIED BY 'jaehpark';"
RUN	echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'jaehpark'@'localhost';"
