Some cool tricks in Shell
=========================

This file contains some useful tricks in Shell.

<br>

```sh
# Change names of files
$ for i in `ls`; do Old=$i; New=`echo $i | sed 's/036\.mp4/036\.3gp/'`; echo $Old $New; done
$ for i in `cat temp.txt`; do Old=$i; New=  echo sed -i '' "s/insertMachine_/_insertMachine/g” <fileName>; done

# Grab first 13 bytes from an flv file and then cat with the flv file to be able to play in VLC

$ dd if=file.flv of=header.bin bs=13 count=1
$ cat header.bin fragment.flv > video.flv

$ cat inputTSV.tsv | awk '{print $5,"\t",$4,"\t"}' | sort -k 1,1


# Merging DASH chunks for a file
$ ls -l | sort -k 9 | grep BabyLaughingHD1_8mwE2N59H5g_itag-134 | awk '{print $9}' | sort -t "." -n -k 3,3 > temp.txt ; ./mergeChunks.sh ; mv output.mp4 ~/xxx.mp4

# Give the sorted last column (file names)
$ ls -l | sort -k 9 | awk '{print $9}’

# Get the number of characters and the unique files
$ for i in `ls | sed 's/_/ /g' | awk '{print $4}' | sort | uniq`; do CHARS=`echo $i | wc -m`; NAME=`echo $i`; echo $CHARS $NAME; done | sort -nk 1 | less

# LD_LIBRARY_PATH
$ LD_LIBRARY_PATH=$FUSION_LIBRARY_PATH mdutil

# Do not export LD_LIBRARY_PATH
#Set it for a specific <command_line>. For example, in above case we are setting it for “mdutil”. Other command_line tools would not look for this LD_LIBRARY_PATH.


# Split a string on underscore, example file names
$ ls -l | sort -k 9 | awk '{print $9}' | sed s/_/\\t/g | cut -f 3

# rsync
$ rsync -av deepanshua.old/ deepanshu/

# http://www.tecmint.com/rsync-local-remote-file-synchronization-commands/

$ rsync -ave ssh --rsync-path=/usr/local/bin/rsync /scr/jtidemann/videos/tmp/ jtidemann@10.198.20.22:/vc/results/jtidemann/testing/qao-dev/



# To remove spaces from file names (replace with underscore or fill it)
$ for i in *' '*; do old="$i"; new=`echo $i | sed 's/ /_/g'`; echo mv "$old" $new; done
$ for i in *' '*; do old="$i"; new=`echo $i | sed 's/ /_/g'`; mv "$old" $new; done
$ for i in *' '*; do old="$i"; new=`echo $i | sed 's/ //g'`; mv "$old" $new; done

# Create and extract a tar.gz archive using command line tar zip
# http://www.zyxware.com/articles/2009/02/26/how-to-create-and-extract-a-tar-gz-archive-using-command-line
# To create a tar.gz archive from a given folder you can use the following command:
$ tar -zcvf tar-archive-name.tar.gz source-folder-name
# This will compress the contents of source-folder-name to a tar.gz archive named tar-archive-name.tar.gz

# To extract a tar.gz compressed archive you can use the following command:
$ tar -zxvf tar-archive-name.tar.gz


# Split string with delimiter colon (:)
$ for i in $(echo $PATH |  tr ":" "\n"); do echo $i; done

# Use sed to change a variable name in a file
$ sed -i '' "s/insertMachine_/_insertMachine/g” <fileName>
$ sed -i '' "s/insertMachine_/_insertMachine/g” * // In all files in the CWD


# Get the symbols from the object file
$ nm -gU /usr/lib/libsqlite3.dylib



# To find strings in a object, or other binary file
$ strings -a /usr/local/Cellar/sqlite/3.8.8.3/lib/libsqlite3.dylib

# Command to find how many lines of code I have written
$ find . -type f \( -name "*.cpp" -o -name "*.hpp" \) | grep -v "server_https\|server_http\|https_examples\|build" | xargs wc -l
$ find . -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*ts.txt" \) | grep -v "server_https\|server_http\|https_examples\|build" | xargs wc -l


# Option-click: Move cursor to location clicked


# How to I find and replace every occurrence of: subdomainA with subdomainB
# in every text file under the /home/www/ directory tree (recursive find/replace).

$ find . -type f -print0 | xargs -0 sed -i '' -e 's/subdomainA/subdomainB/g'

# Replace all LOG( with //LOG(
$ find . -type f -print0 | xargs -0 sed -i '' -e 's/LOG(/\/\/LOG(/g’

# Find how many threads were used in a log file
$ cat sample_0.log  | awk '{print $3}' | sort | uniq

# Convert a file to all upper-case
$ tr a-z A-Z < employee.txt

# Convert a file to all lower-case
$ tr A-Z a-z < department.txt
```

###grep
```sh
Beginning of line (^): grep "^Nov 10" logFile.txt
End of the line ($): grep "terminating.$" messages.txt
Count of empty lines (^$): grep -c "^$" messages.txt
Single Character (.): The special meta-character "." (dot) matches any character except the end of the line character
Zero or more occurrence (*): The special character "*" matches zero or more occurrence of the previous character
                             grep "kernel: *." *: matches for kernel and colon symbol followed by any number of spaces/no space and “.” matches any single character
One or more occurrence (\+): grep "hi \+hello" input.txt
Zero or one occurrence (\?): grep "hi \?hello" input.txt
$ grep  -v "^#\|^'\|^\/\/" logFile.txt: This command searches for the line which does not start with # or single quote (‘) or double front slashes (//)
Word boundary (\b): grep -i "\bthe\b" logFile.txt: \b is to match for a word boundary. \b matches any character(s) at the beginning (\bxx) and/or end (xx\b) of a word
```

###find
```sh
# How to find all the files greater than certain size?
$ find . -type f -size +100M

# How to find files that are not modified in the last x number of days?
$ find . -mtime +60  # 60 days

# How to find files that are modified in the last x number of days?
$ find . –mtime -2  # 2 days

# How to delete all the archive files with extension *.tar.gz and greater than 100MB?
$ find / -type f -name *.tar.gz -size +100M -exec ls -l {} \;
$ find / -type f -name *.tar.gz -size +100M -exec rm -f {} \;
```

###xargs
```sh
# xargs is a very powerful command that takes output of a command and pass it as argument to another command

# Delete too many files using rm
$ find ~ -name ‘*.log’ -print0 | xargs -0 rm -f

# Get a list of all the *.conf file under /etc/
$ find /etc -name "*.conf" | xargs ls –l
```

###sort
```sh
# Sort a text file in ascending order
$ sort names.txt

# Sort a text file in descending order
$ sort -r names.txt

# Sort a colon delimited text file on 2nd field
$ sort -t: -k 2 names.txt
```

###cut
```sh
# Display the 1st field (employee name) from a colon delimited file
$ cut -d: -f 1 names.txt

# Display 1st and 3rd field from a colon delimited file
$ cut -d: -f 1,3 names.txt

# Display only the first 8 characters of every line in a file
$ cut -c 1-8 names.txt
```

###sed
```sh
$ sed 'ADDRESSs/REGEXP/REPLACEMENT/FLAGS' filename
$ sed 'PATTERNs/REGEXP/REPLACEMENT/FLAGS' filename

#     s is substitute command
#     / is a delimiter
#     REGEXP is regular expression to match
#     REPLACEMENT is a value to replace

# FLAGS can be any of the following :
#     g Replace all the instance of REGEXP with REPLACEMENT
#     n Could be any number,replace nth instance of the REGEXP with REPLACEMENT.
#     p If substitution was made, then prints the new pattern space.
#     i match REGEXP in a case-insensitive manner.
#     w file If substitution was made, write out the result to the given file.
#     We can use different delimiters ( one of @ % ; : ) instead of /

# Examples:
# Substitute Word "Linux" to "Linux-Unix" s// (only first matched Linux is replaced)
$ sed 's/Linux/Linux-Unix/' thegeekstuff.txt

# Substitute all Appearances of a Word Using sed s//g
$ sed 's/Linux/Linux-Unix/g' thegeekstuff.txt

# Substitute Only 2nd Occurrence of a Word Using sed s//2
$ sed 's/Linux/Linux-Unix/2' thegeekstuff.txt

# Delete Last X Number of Characters From Each Line (This example deletes last 3 characters from each line)
$ sed 's/...$//' thegeekstuff.txt

# Delete all the comment lines from a file
$ sed -e 's/#.*//' thegeekstuff.txt

# Delete all the comment lines from a file and then remove those blank/empty lines
$ sed -e 's/#.*//;/^$/d' thegeekstuff.txt
```

###awk
```sh
$ awk '/search pattern1/ {Actions}
       /search pattern2/ {Actions}' file

# In the above awk syntax:
#     search pattern is a regular expression.
#     Actions – statement(s) to be performed.
#     several patterns and actions are possible in Awk.
#     file – Input file.
#     Single quotes around program is to avoid shell not to interpret any of its special characters.

Awk Working Methodology:
#     Awk reads the input files one line at a time.
#     For each line, it matches with given pattern in the given order, if matches performs the corresponding action.
#     If no pattern matches, no action will be performed.
#     In the above syntax, either search pattern or action are optional, But not both.
#     If the search pattern is not given, then Awk performs the given actions for each line of the input.
#     If the action is not given, print all that lines that matches with the given patterns which is the default action.
#     Empty braces with out any action does nothing. It wont perform default printing operation.
#     Each statement in Actions should be delimited by semicolon.

#Examples:
# By default Awk prints every line from the file
$ awk '{print;}' employee.txt

# Print column 2 and 5
$ awk '{print $2,$5;}' employee.txt

# Find the employees who has employee id greater than 200
$ awk '$1 >200' employee.txt

# Print the list of employees in Technology (4th column) department
$ awk '$4 ~/Technology/' employee.txt
```
