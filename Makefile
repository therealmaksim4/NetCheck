all:
	gcc -O3 -Iinclude src/* -o bin/netcheck
	sudo install -m 0755 bin/netcheck /usr/bin/netcheck
	sudo rm -rf /usr/src/NetCheck
	sudo cp -r ../NetCheck /usr/src/NetCheck
	sudo rm -rf /usr/src/NetCheck/.git
