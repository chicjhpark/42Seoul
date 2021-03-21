docker pull debian:buster
docker run -it -p 80:80 -p 443:443 debian:buster
apt-get update
apt-get -y install nginx
service nginx start
apt-get -y install openssl
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.key -out localhost.crt
mv localhost.crt etc/ssl/certs/
mv localhost.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.crt etc/ssl/private/localhost.key
apt-get -y install vim
apt-get -y install mariadb-server php-mysql
service mysql start
apt-get -y install php7.3-fpm
apt-get -y install wget
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html
chown -R www-data:www-data /var/www/html/wordpress
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
