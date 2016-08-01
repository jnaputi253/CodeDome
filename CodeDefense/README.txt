Team Members:
-	Juan Naputi
-	Ashley McBride
-	Stormi Sprague

C Program Fixes
==================
a) Person.c / Person.h
	- Cleaned up stdin if input exceeded the buffer limit.

b) Number.c / Number.h
	- Implemented proper bound checks for overflow cases

c) FileHandler.c / FileHandler.h
	- Added checks to prevent paths for input
	- Added code to prevent input and output files from being the same

d) Password.c / Password.h
	- Better hash for the password
	- Added better password checks to ensure standard of 1 uppercase letter, 1 lowercase letter, 1 		  	number, 1 special character, and no spaces is
	  enforced.  You can, of course, have multiple of the above as long as 
	  the password length is within the bounds; however, this rule doesn't
	  apply to spaces.

e) main.c
	- Just minor fixes in regards to function changes and formatting output.	  Nothing major here has been added to warrant posting.

