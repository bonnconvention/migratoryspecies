FROM php:5.6-apache
MAINTAINER cristian@romanescu.ro

RUN apt-get update && apt-get install -yq \
    libfreetype6-dev \
    libjpeg62-turbo-dev \
    libmcrypt-dev \
    libpng12-dev \
    libicu-dev \
    libldap2-dev \
    libcurl4-openssl-dev \
    libxml2-dev \
    libmemcached-dev libmemcached11 \
    && ln -fs /usr/lib/x86_64-linux-gnu/libldap.so /usr/lib/ \
    && a2enmod rewrite

RUN docker-php-ext-install gettext gd ldap mbstring mcrypt opcache pdo pdo_mysql simplexml xml zip
