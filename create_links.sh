#!/usr/bin/env zsh
# create needed symlinks

script_dir="$(dirname "$0")"
script_dir2="$(dirname "$script_dir")"
nginx_dir="/etc/nginx/"
www_dir="/var/www/"
ln -s "${script_dir2}nginx/DjangoSite.conf" "${nginx_dir}sites-available/DjangoSite.conf" || exit 1
ln -s "${nginx_dir}sites-available/DjangoSite.conf" "${nginx_dir}sites-enabled/DjangoSite.conf" || exit 1
ln -s "${script_dir2}static/" "${www_dir}DjangoSite/static/" || exit 1

echo "symlinks has been created"

exit 0
