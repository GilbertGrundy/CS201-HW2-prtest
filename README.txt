Gilbert Grundy 
CS201
HW2
Proof Read Testing Program

I wish I had looked at your hints before I finished 
the program! I had looked at a few libraries on a
couple of websites - of which I've placed at the 
bottom of my program in comments - and slowly worked
out a way to get the time to create scores.

I ended up using a different function to the one you
had recommended - clock_gettime() - it gave me time
values with a struct timespec, which had two useful
data members, one with seconds, and another with 
nanoseconds. So I had to do a little conversion, but
it was the first solution I found, and it seemed to
work! However, I included the -std=c99 flag into my
Makefile after I finished, and it stopped compiling!
I believe the function I used must be in the c11 version?
Anyway, wasn't a huge problem to use the gettimeofday()
function instead.

I've made my program have two const ints, one for the
size of the array, and another for the number of rounds.
Since the text file shouldn't be longer than 10 lines 
with 60 characters, I've made MAX to be 600. The program
will stop reading a text file if it hits the max. I figured
the program would be nicer if you could just edit the 
ROUND_AMOUNT once for a longer game.

I think I could have created more functions to make
the program more streamlined and easier to follow,
but with the unfamiliar data members I was using, I 
decided it might be a fair bit of trial and error to
get right. However, if I had more time, I would definitely
implement a score function, and a print score function.

                 EXAMPLE RUN:


* * * * * * * * * * * * * * * * * * * * * * * * * *

$ ./prtest pr.txt

Most potent, grave, and reverend signiors,
My very noble and approved good masters,
That I have ta'en away this old man's daughter,
It is most true; true, I have married her:
The very head and front of my offending.
Hath this extent, no more. Rude am I in my speech,
And little bless'd with the soft phrase of peace:
For since these arms of mine had seven years' pith,
Till now some nine moons wasted, they have used
Their dearest actdon in the tented field,

y
Incorrect for 7375 points.

Most potent, grave, and reverend signiors,
My very noble and approved good masters,
That I have ta'en away this old man's daughter,
It is most true; true, I have married her:
The very head and front of my offending.
Hath this extent, no more. Rude am I in my speech,
And little bless'd with the soft phrase of peace:
For since these arms of mine had seven years' pith,
Till now some nine moons wasted, they have used
Their dearest action in the tented field,

n
Incorrect for 5972 points.

Most potent, grave, and reverend signiors,
My very noble and approved good masters,
That I have ta'en away this old man's daughter,
It is most true; true, I have married her:
The very head and front of my offending.
Hath this extent, no more. Rude am I in my speech,
And little bless'd with the soft phrase of peace:
For since these arms of mine had seven years' pith,
Till now some nine moons wasted, they have used
Their dearest action in the tented field,

y
Correct for 1497 points

3 rounds, total score 14844 points. 

* * * * * * * * * * * * * * * * * * * * * * * * * *
