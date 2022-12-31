if [ "$1" = "-e" ]
then
	tar -xvzf $2
else
	tar -cvzf $2 $*
fi
