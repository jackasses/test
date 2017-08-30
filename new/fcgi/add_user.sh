#/bin/bash
#$1 user
#$2 file
#$3 pw
string="$1"
search="$1:\$apr1"
pw="$2"
file="$3"
result=$(grep -n "$search" "$file")
alt=${result%%:*}
if [ -n "$alt" ]; then
	sudo sed --in-place "$alt d" "$file"
fi
echo $alt
sudo sh -c "echo -n '$string:' >> $file"
sudo sh -c "openssl passwd -apr1 "$pw">> $file"

