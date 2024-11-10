MKSHELL=$PLAN9/bin/rc

clean:V:
	find . -name a.out -exec rm -f '{}' '+'
