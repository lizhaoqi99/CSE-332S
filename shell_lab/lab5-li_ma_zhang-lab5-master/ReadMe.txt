CSE332S Lab 5
Team Name: li_ma_zhang-lab5
Steve Li, wustlkey: zhaoqi.li
Xiaowen Ma, wustlkey:maxiaowen
Claire Zhang, wustlkey: zhangbin

We got approved by Professor Shidal to extend the deadline to the 14th.

[Distribution of Work]
We wrote all parts of lab 5 together. No person has a major responsibility for writing one part of lab 5.

[Errors]
One error that we had was that when we were trying to decrease or increase the link count, we directly modified the pointer without dereferencing it. This resulted in odd numbers showing up during our testing. Later we found out that we forgot to dereference the pointer and solved the problem by dereferencing the pointer before increasing or decreasing it.

[Testing 1: all commands except rm]

To test all commands in Lab 5 except rm (rm is tested later with new code in main, see Testing 2), the following code is used in the main:

vector<char> vec1 = { 'a', 'b', 'c', '\n', 'd', 'e', 'f' };
vector<char> vec2 = { 'X', ' ', 'X', 'X', '2' };
text->write(vec1);
img->write(vec2);
fs->addFile("root/", dir1);
fs->addFile("root/dir1/", dir2);
fs->addFile("root/dir1/", img);
fs->addFile("root/dir1/", text);
fs->addFile("root/dir1/dir2/", dir3);

Then many tests were run on our commands in the terminal. Below are the test process and results. Comments are written below some testing or groups of testing to describe the performance of our program.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls -l
dir1    directory        size: 22

*comments:
The LSCommand with options -l will call the ReadMetadataFileVisitor to visit the root(of type directory) and besides the names of the files it contains(in this case “dir1”), it will also print out the file type, which is “directory” in  this case and the size of its content, which is 22(for the total length of all the names of the files it contains)

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir1

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ls
dir2
img.img
text.txt

*comment: 
The LSCommand without any option will call the ReadFileVisitor to visit dir1(of type directory) and prints out the names of the files it contains(in this case “dir2”, “img.img” and “text.txt”)

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ls -l
dir2    directory        size: 5
img.img   image    size: 4
text.txt      text     size: 7

*comments:
The LSCommand with options -l will call the ReadMetadataFileVisitor to visit the dir1(of type directory) and besides the names of the files it contains(in this case “dir2”, “img.img” and “text.txt”), it will also print out the file types(which is “directory”, “image” and “text” respectively in  this case) and the sizes of the files’ contents(which are “5”, “4” and “7” respectively)

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ds text.txt
abc
def

*Comments: Calling ds successfully and correctly displays the content in text file in the correct format.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ds text.txt -d
abcdef

*Comments: Calling ds with -d successfully and correctly displays the content in text file without format.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ds img.img
XX
X

*Comments: Calling ds successfully and correctly displays the content in an image file in the correct format.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ds img.img -d
X XX

*Comments: Calling ds with -d successfully and correctly displays the content in an image file without format.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ls
dir2
img.img
text.txt

*Comments: Calling ls without -l successfully and correctly displays the content in the dir1 directory.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ cp text.txt root/dir1/dir2/

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ cp img.img root/dir1/dir2/

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ cd dir2

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2 $ ls
dir3
text.txt
img.img

*Comments: These testing above show that cp is able to successfully and correctly copy the files of interests to a designated location in the file system.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2 $ cat text.txt -a
abcdef
Please enter your input (Enter ':wq' to append your input, enter ':q' to quit):
12345
ghi
:wq

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2 $ ds text.txt
abc
def
12345
ghi

*Comments: These testings above show that calling cat with -a allows new input to be appended to the current text file. The program successfully and correctly prompted the user to input and to continue to input until :wq is detected, after which the current appending process is stopped and the input is appended to the text file. Calling ds again successfully and correctly displays the updated content of the text file in the correct format.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2 $ cat img.img
Please enter your input (Enter ':wq' to override your input, enter ':q' to quit):
XXXX2
input is: XXXX2
:wq

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2 $ ds img.img
XX
XX

*Comments: These testings above show that calling cat without -a allows new input to be overwritten on top of the current image file. The program successfully and correctly prompted the user to input until :wq is detected, after which the current process is stopped and the input is used to replace the content of the image file. Calling ds again successfully and correctly displays the new content of the image file in the correct format.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2 $ ls
dir3
text.txt
img.img

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2 $ sym text.txt root/dir1/dir2/dir3/

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2 $ sym img.img root/dir1/dir2/dir3/

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2 $ cd dir3

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3 $ ls
text.txt
img.img

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3 $ ds text.txt
abc
def
12345
ghi

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3 $ ds img.img
XX
XX

*Comments: These testing above show that calling sym successfully and correctly creates a proxy of the original file in the designated location. The proxy contains the original file’s content and format.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3 $ touch dir4

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3 $ sym text.txt root/dir1/dir2/dir3/dir4/

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3 $ sym img.img root/dir1/dir2/dir3/dir4/

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3 $ rm text.txt

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3 $ ls
img.img
dir4

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3 $ cat img.img
Please enter your input (Enter ':wq' to override your input, enter ':q' to quit):
XXXXXXXXX3
input is: XXXXXXXXX3
:wq

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3 $ ds img.img
XXX
XXX
XXX

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3 $ cd dir4
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3/dir4 $ ls
text.txt
img.img

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3/dir4 $ ds text.txt
abc
def
12345
ghi

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3/dir4 $ ds img.img
XXX
XXX
XXX

*Comments: These testing above show that the program successfully and correctly created new proxies of the original proxies in a different designated location. The new proxies contain the original proxies’ content and in the correct format. After rewriting the content in the original proxy, the new proxy also has the updated content and in the correct format. When the original proxy is deleted, the new proxy still keeps the correct content.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3/dir4 $ cat text.txt -a
abcdef12345ghi
Please enter your input (Enter ':wq' to append your input, enter ':q' to quit):
:q

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1/dir2/dir3/dir4 $ q

*Comments: These testings above show that during the cat command, when the user inputs :q, the program successfully and correctly exits.

[Testing 2: command rm]
Testing 2a:
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls
dir1

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir1
Directory isn't empty.
command failed

*comments:
Try to rm dir1 which has dir2 and img.img in it(i.e. Non-empty), thus would cause error.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ cd dir1
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ls
dir2
img.img

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ rm dir2
Directory isn't empty.
command failed

*comments:
Try to rm dir2 which has text.txt in it(i.e. dir2 is Non-empty directory), thus would cause error.

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ rm dir2 -r
Directory isn't empty.

*comments:
Try to rm dir2 recursively which has text.txt in it. The first time it calls remove on dir2 will generate output “Directory isn’t empty” since there is a text file(which is close) in dir2, and then because of the option “-r”, the command will go into dir2 and try to remove the files in dir2(in this case “text.txt”), after it successfully remove “text.txt”, dir2 becomes an empty directory, thus the second time we try to remove dir2, we will successfully delete dir2(shown by the next output--see below)

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root/dir1 $ ls
img.img

*comments:
After recursively removing dir2, we can see that dir1 now only contains img.img in it(dir2 and text.txt in dir2 are deleted)

Testing 2b: img.img is open vs. img.img is close
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir1 -r
Directory isn't empty.
Directory isn't empty.
File is currently in use

*comments:
Recursively removing dir1 will fail since the image file img.img is currently open(which should not be removed from the file system), however, if img.img is close, dir1 along with the files it contains will be deleted, thus the root would contain no files after this operation--see below

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ rm dir1 -r
Directory isn't empty.
Directory isn't empty.
To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $ ls

To quit: q, For a list of commands: help, For information about a specific command: help <command name>
root $



 
