# Anagram-Hashing
Write a program to print out all anagrams of a specified string. Two strings are anagrams of each
another if by rearranging letters of one of the strings you can obtain another. For example, the string
"toxic" is an anagram of "ioxct". For the purpose of this project, we are only interested in those
anagrams of a given string which appear in the dictionary. The dictionary you should use has been
provided “words.txt”.
# Algorithm and Implementation
Since, we will be performing multiple anagram queries, our first step is to load all of the (25,000) words
in the dictionary into an appropriate data structure. A primary requirement is that one must be able to
efficiently search this data structure to look for anagrams of a given word. A clever trick that we will
use to facilitate this is to first sort the letters of every word we insert into our data structure (you may
use any sort you wish to produce a key for each word. For example, the key for the string "toxic" is
"ciotx", similarly the key for both "star" and "rats" is "arst". We will then use a hash table to store pairs
of strings, where the pair consists of the original word and its key.
When performing insertions into the hash table, we will compute the hash of the key of the word to
compute the correct bucket (location in the hash table). This approach guarantees that all words which
are anagrams of one another are stored in the same bucket of the hash table. Similarly, when we are
searching for anagrams, we will first compute the key of the word we are searching for, then hash the
key, then search that bucket for anagram matches. You should feel free to use any appropriate hash
function for hashing strings (but please cite any source which you use). Also, make sure your function
is efficient and does not hash completely unrelated sets of anagrams to the same bucket *if possible*. If
it does, handle the collisions as you see fit (e.g. linked processing). Also note that if you must probe for
a given set of anagrams in time greater than or equal to O(logn), then you must revise your hash
function. You will be graded heavily on the performance of the efficiency of your function.
# Details
The hash table code which you provide only needs to have the minimum functionality needed to solve
this problem. You may fix a size for your hash table for efficient searching. It is recommended that the
final hash table you submit contain at least 25,000 buckets. (For debugging your code, it is suggested
that you work with a much smaller practice dictionary, perhaps 10 words, and a much smaller hash
table, perhaps 8-10 buckets (depending on whether or not there are any anagrams in the dictionary).
Make sure your table size is prime to help reduce collisions. Remember it is ok to sacrifice space for
speed -- that is what hashing is all about. That said, your table should not be bigger than 200,000.
1You may disregard any words in the dictionary which contain any punctuation characters. Also, you
should convert any uppercase characters to lowercase (thus you are only representing words that
contain all lower case characters).
Your program should read anagram queries from an input file (“input.txt”). Each query in the file
will be on its own line and will simply consist of a string. The output file (“output.txt”) should contain
the original string, then the number of matching anagrams, followed by those anagrams. An example
input file and the resulting output file have been provided. Your output file should match this format
exactly, except that the matching anagrams you output may be ordered differently.
